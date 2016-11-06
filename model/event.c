/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    Az eseményeket reprezentáló adatszerkezetethez tartozó fügvények.
*/

//mallochoz szügséges
#include <stdlib.h>
//strcpy-hez
#include <string.h>
#include "Event.h"
#include "Visitor.h"

//Új üres esemény
struct Event* newEvent(int id, char* name)
{
	struct Event* _this = malloc(sizeof(struct Event));
	_this->id = id;
	strcpy(_this->name, name);
	_this->size = 0;
	_this->_realSize = defaultArraySize;
	Visitor**  _eventArray = malloc(_this->_realSize * sizeof(Visitor*));
	_this->eventArray = _eventArray;
	return _this;
}


//Látogató hozzáadását teszi lehetőve az eseményhez
/*	Ha a tömb betelt, akkor dupla méretűt deklarálunk, átmásoljuk az adatokat
 és a régit töröljük a C++ STD Vector mintájára.*/
int addVisitorToEvent(Event* event, Visitor* visitor)
{
	int i;
	
	if(event->_realSize > event->size)
	{
		event->eventArray[event->size] = visitor;
		event->size++;
	}
	else
	{
		event->_realSize *= 2;
		Visitor**  _eventArray = malloc(event->_realSize * sizeof(Visitor*));
		for(i = 0; i < event->size; ++i)
		{
			_eventArray[i] = event->eventArray[i];
		}

		/*Felszabadítjuk a címeket tároló tömböt,
		de az elemeket nem. Azok címeit az új tömb már tárolja.*/
		Visitor** arr = lines -> eventArray;
		free(arr);

		//A helyérekerül az új nagyobb tömb címe.
		lines -> eventArray = _eventArray;
		
		//Elvégezzük a beszúrást
		event->eventArray[event->size] = visitor;
		event->size++;
	}
	return 0;
}


//Látogató törlése az eseményről
int deleteVisitorFromEvent(Event* event, Visitor* visitor);
{
	int i, l = 0;
	Visitor**  _eventArray = malloc(event -> _realSize * sizeof(Visitor*));
	for(i = 0; i < event->size; ++i)
	{
		if(event->eventArray[i] != visitor)
		{
			_eventArray[l] = lines->eventArray[i];
		}
		else
		{
			l = i-1;
			freeVisitor(event->eventArray[i]);
		}
		++l;
	}
	Visitor** arr = event -> eventArray;
	free(arr);
	event -> eventArray = _eventArray;
	event->size--;
	return 0;
}


//Index szerinti keresés a látogatók között
struct Visitor* getVisitorFromEventById(Event* event, int id){
	return event->eventArray[id];
}

/*Az Event típus destruktora
Kell destrukfor, mivel az eventArray külön álló egységet képez a memóriában
Törli a tömb által mutatott elemeket is!*/
void freeEvent(Event* event)
{
	int i;
	for(i = 0; i < event->size; ++i)
	{
		freeVisitor(event->lineArray[i]);
	}
	free(event->eventArray);
	free(event);
}