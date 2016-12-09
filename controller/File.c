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

Events* eventsReaderForBinFiles(FILE* f)
{
    Events* events = newEvents();
	if(filesize(name) > 0)
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
    char name[nameSize];
    fread(name, nameSize+1, 1, f);

    Event* event = newEvent(id, name);

    int i;
    for(i = 0; i<size; ++i)
    {
        addVisitorToEvent(event, visitorReaderForBinFiles(f, i));
    }

    return events;
}

Visitor* visitorReaderForBinFiles(FILE* f, int id)
{
    int nameSize;
    fread(&nameSize,sizeof(nameSize), 1, f);
    char name[nameSize];
    fread(name, nameSize+1, 1, f);
    int emailSize;
    fread(&emailSize,sizeof(emailSize), 1, f);
    char email[emailSize];
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