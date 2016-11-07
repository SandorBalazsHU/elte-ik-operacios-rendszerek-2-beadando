/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
    Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    Az eseményeket tároló adatszerkezetet tartalmazó fejléc.
*/

#ifndef EVENTS_H
#define EVENTS_H

#include <stdio.h>
#include "Event.h"

//A eseményt modellező adatszerkezet
/*
+------------------------+
|         Events         |
| +--------------------+ |
| |    int size        | |
| +--------------------+ |
| +--------------------+ |
| |    int _realSize   | |
| +--------------------+ |
| +--------------------+ |            +--------------------+
| | Event** eventArray | |===========>|    eventArray[]    |
| +--------------------+ |            | +----------------+ |              +----------------+
+------------------------+            | |     Event*     | | ===========> |     Event      |
                                      | +----------------+ |              +----------------+
                                      | +----------------+ |              +----------------+
                                      | |     Event*     | | ===========> |     Event      |
                                      | +----------------+ |              +----------------+
                                      | +----------------+ |              +----------------+
                                      | |     Event*     | | ===========> |     Event      |
                                      | +----------------+ |              +----------------+
                                      |         ...        |                      ...
                                      +--------------------+
*/

typedef struct Events
{
	//Felvett rendezvények száma
	int size;
	//A tároló tömb valós mérete
	int _realSize;
	//Az eseményekre mutató pointerek tömbje
	Event** eventsArray;
}Events;

//Az alapértelmezett tároló tömb mérete
static const int defaultArraySize = 5;

//Új üres eseménytároló létrehozásához
struct Event* newEvents();

//Esemény hozzáadását teszi lehetőve az eseménytárolóhoz
/*	Ha a tömb betelt, akkor dupla méretűt deklarálunk, átmásoljuk az adatokat
 és a régit töröljük a C++ STD Vector mintájára.*/
int addEventToEvents(Events*, Event*);

//Esemény törlése az eseménytárolóból
int deleteEventFromEvents(Events*, Event*);

//Index szerinti keresés az események között
struct Event* getEventFromEventsById(Events*, int);

/*Az Events típus destruktora
Kell destrukfor, mivel az eventArray külön álló egységet képez a memóriában
Törli a tömb által mutatott elemeket is!*/
void freeEvents(Events*);

#endif