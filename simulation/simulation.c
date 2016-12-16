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

#include "../model/Events.h"
#include "../view/ConsoleIO.h"

int simulation(Events* events)
{
    printMessage("A szimuláció Elkezdődött!");
	pid_t parentPid = getpid();
	simulationStateMessage("KOS(Szülő)", parentPid, "Fut!");
    int communicationPipe[2];
	pid_t childPid;
	char pipeBuffer[100];

	if (pipe(communicationPipe) == -1) 
	{
		errorMessage("Hiba a pipe nyitaskor!");
		return 1;
	}
	
	childPid = fork();
	if (childPid == -1) 
	{
		errorMessage("Fork hiba!");
		return 1;
	}

	if (childPid == 0) 
	{
		pid_t myChildPid = getpid();
		simulationStateMessage("Partner(gyerek)", myChildPid, "Fut!");
		sleep(3);
		close(communicationPipe[1]);
		read(communicationPipe[0], pipeBuffer, sizeof(pipeBuffer));
		simulationStateMessage("Partner(gyerek)", myChildPid, "Az olvasott üzenet:");
		printMessage(pipeBuffer);
		close(communicationPipe[0]);
		exit(EXIT_SUCCESS);
	} 
	else 
	{
		close(communicationPipe[0]);
		write(communicationPipe[1], "Hajra Fradi!",13);
		close(communicationPipe[1]);
		fflush(NULL);
		wait();
		simulationStateMessage("KOS(Szülő)", getpid(), "Leáll!");
        printMessage("A szimuláció végetért!");
	}
}