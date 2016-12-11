/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A fájlkezelésért felelős függvények
*/

#include <stdio.h>
#include <time.h>
#include "File.h"
#include "../model/Events.h"
#include "../model/Event.h"
#include "../model/Visitor.h"

void eventsWriterForBinFiles(Events* events, FILE* f)
{
    fwrite(&events->size, sizeof(events->size), 1, f);
    int i;
    for(i = 0; i<events->size; ++i) eventWriterForBinFiles(getEventFromEventsById(events, i), f);
}

void eventWriterForBinFiles(Event* event, FILE* f)
{
    fwrite(&event->size, sizeof(event->size), 1, f);
    int nameSize = (int) strlen(event->name);
    fwrite(&nameSize, sizeof(nameSize), 1, f);
    fwrite(event->name, sizeof(char), nameSize+1, f);
    int i;
    for(i = 0; i<event->size; ++i)visitorWriterForBinFiles(getVisitorFromEventById(event, i), f);
}

void visitorWriterForBinFiles(Visitor* visitor, FILE* f)
{
    int nameSize = (int) strlen(visitor->name);
    fwrite(&nameSize, sizeof(nameSize), 1, f);
    fwrite(visitor->name, sizeof(char), nameSize+1, f);
    int emailSize = (int) strlen(visitor->email);
    fwrite(&emailSize, sizeof(emailSize), 1, f);
    fwrite(visitor->email, sizeof(char), emailSize+1, f);
    fwrite(&visitor->date, sizeof(&visitor->date), 1, f);
}

Events* eventsReaderForBinFiles(FILE* f)
{
    Events* events = newEvents();
	if(getFileSize(f) > 0)
	{
		int size;
		fread(&size,sizeof(size),1,f);
		int i;
		for(i = 0; i<size; ++i) addEventToEvents(events, eventReaderForBinFiles(f, i));
	}
	return events;
}

Event* eventReaderForBinFiles(FILE* f, int id)
{
    int size;
    fread(&size,sizeof(size), 1, f);
    int nameSize;
    fread(&nameSize,sizeof(nameSize), 1, f);
    char name[nameSize+1];
    fread(name, nameSize+1, 1, f);

    Event* event = newEvent(id, name);

    int i;
    for(i = 0; i<size; ++i)
    {
        addVisitorToEvent(event, visitorReaderForBinFiles(f, i));
    }
    return event;
}

Visitor* visitorReaderForBinFiles(FILE* f, int id)
{
    int nameSize;
    fread(&nameSize,sizeof(nameSize), 1, f);
    char name[nameSize+1];
    fread(name, nameSize+1, 1, f);
    int emailSize;
    fread(&emailSize,sizeof(emailSize), 1, f);
    char email[emailSize+1];
    fread(email, emailSize+1, 1, f);
    time_t date;
    fread(&date, sizeof(date), 1, f);

    Visitor* visitor = newVisitor(id, name, email, date);

    return visitor;
}

FILE* openBinFileForRead(const char* name)
{
	FILE* f;
	f=fopen(name,"rb");
	if (f==NULL)
	{
		f=fopen(name,"wb+");  if (f==NULL) printf("Nem sikerült létrehozni a filet!\n");
		fclose(f);
		f=fopen(name,"rb");   if (f==NULL) printf("Hiba az olvasásra nyitás során!\n");
	}
	return f;
}

FILE* openBinFileForWrite(const char* name)
{
	FILE* f;
	f=fopen(name,"wb+");
	if (f==NULL)
	{
		printf("Hiba az írásra nyitás során\n");
	}
	return f;
}

int getFileSize(FILE* f)
{
	fseek(f, 0, SEEK_END);
    int fileSize = ftell(f);
    rewind(f);
    return(fileSize);
}