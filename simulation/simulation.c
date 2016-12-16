/*
    Tárgy: Elte IK Operációs rendszerek 2. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-king-of-stands

    A szimuláció.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "./Simulation.h"
#include "../model/Events.h"
#include "../model/Event.h"
#include "../view/ConsoleIO.h"

void _signalHandler(int signumber)
{
  if(signumber == SIGTERM) simulationStateMessage("KOS(Szülő)", getpid(), "SIGTERM - szignál érkezett!");
  simulationMessage("A szervező megérkezett a helyszínre!");
}

void _sendSignal()
{
	simulationStateMessage("Partner(gyerek)", getpid(), "SIGTERM - szignál elküldve!");
	kill(getpid(), SIGTERM);
}

int simulation(Events* events)
{
    printMessage("A szimuláció Elkezdődött!");
	pid_t parentPid = getpid();
	simulationStateMessage("KOS(Szülő)", parentPid, "Fut!");

	//Pipe
    int communicationPipe[2];
	pid_t childPid;
	char pipeBuffer[5];
	if (pipe(communicationPipe) == -1) 
	{
		errorMessage("Hiba a pipe nyitaskor!");
		return 1;
	}

	//Signal
	signal(SIGTERM,_signalHandler);

	//Fork
	childPid = fork();
	if (childPid == -1) 
	{
		errorMessage("Fork hiba!");
		return 1;
	}

	//Folyamatok
	if (childPid == 0) 
	{
		//Gyerek
		pid_t myChildPid = getpid();
		simulationStateMessage("Partner(gyerek)", myChildPid, "Fut!");

		sleep(3);
		//Pipe - 1
		close(communicationPipe[1]);
		read(communicationPipe[0], pipeBuffer, sizeof(pipeBuffer));
		simulationStateMessage("Partner(gyerek)", myChildPid, "Az olvasott üzenet:");
		simulationMessage("A rendezvény helyszíne: ");
		simulationMessage(pipeBuffer);

		//Pipe - 2
		simulationMessage("A rendezvény résztvevői: ");
		read(communicationPipe[0], pipeBuffer, sizeof(pipeBuffer));
		simulationStateMessage("Partner(gyerek)", myChildPid, pipeBuffer);
		char *garbage = NULL;
		int eventSize = strtol(pipeBuffer, &garbage, 0);
		int i; for(i=0; i<3; i++)
		{
			read(communicationPipe[0], pipeBuffer, sizeof(pipeBuffer));
			simulationMessage(pipeBuffer);
		}
		close(communicationPipe[0]);

		//Signal
		_sendSignal();

		simulationStateMessage("Partner(gyerek)", myChildPid, "Leáll!");
		exit(EXIT_SUCCESS);
	} 
	else 
	{
		//Szülő
		Event* event = getEventFromEventsById(events, 0);

		//Pipe - 1
		close(communicationPipe[0]);
		char* eventName = getEventFromEventsById(events, 0)->name;
		_stringSerializer(eventName, pipeBuffer);
		write(communicationPipe[1], pipeBuffer, sizeof(pipeBuffer));
		fflush(NULL);

		//Pipe - 2
		char eventSizeToStringTmp[15];
		sprintf(eventSizeToStringTmp, "%d", event->size);
		simulationStateMessage("KOS(Szülő)", parentPid, eventSizeToStringTmp);
		_stringSerializer(eventSizeToStringTmp, pipeBuffer);
		write(communicationPipe[1], pipeBuffer, sizeof(pipeBuffer));

		int i; for(i=0; i<event->size; i++)
		{
			char* visitorName = getVisitorFromEventById(event, i)->name;
			_stringSerializer(visitorName, pipeBuffer);
			write(communicationPipe[1], pipeBuffer, sizeof(pipeBuffer));
		}

		close(communicationPipe[1]);
		fflush(NULL);

		//Bevár
		wait();

		simulationStateMessage("KOS(Szülő)", parentPid, "Leáll!");
        printMessage("A szimuláció végetért!");
	}
}

void _stringSerializer(char* in, char* buffer)
{
	strcpy(buffer, in);
}