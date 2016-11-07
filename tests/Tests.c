/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetethez tartozó fügvények.
*/

#include <string.h>
#include <stdio.h>
#include "./Tests.h"
#include "./view/ConsoleIO.h"
#include "./model/Events.h"
#include "./model/Event.h"
#include "./model/Visitor.h"
#include "./controller/File.h"

//A teszteket egyszerre futtató függvény.
int test()
{
    //A visitor adatszerkezet tesztje.
    int testVisitor();

    //Az Event adatszerkezet tesztje kevesebb mint 5 elemre.
    int testEvent();

    //Az Event adatszerkezet tesztje több mint 5 elemre.
    int testEventMax();

    //Az Events adatszerkezet tesztje kevesebb mint 5 elemre.
    int testEvents();

    //Az Events adatszerkezet tesztje több mint 5 elemre.
    int testEventsMax();
}

//A visitor adatszerkezet tesztje.
int testVisitor()
{
    Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
    freeVisitor(visitor1);
}

//Az Event adatszerkezet tesztje kevesebb mint 5 elemre.
int testEvent()
{
    Event* event1 = newEvent(1,"event1");
        Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
        addVisitorToEvent(event1, visitor1);
        Visitor* visitor2 = newVisitor(1, "visitor2", "visitor2@mail.org", getDate());
        addVisitorToEvent(event1, visitor2);
        Visitor* visitor3 = newVisitor(2, "visitor3", "visitor3@mail.org", getDate());
        addVisitorToEvent(event1, visitor3);
    freeEvent(event1);

}

//Az Event adatszerkezet tesztje több mint 5 elemre.
int testEventMax()
{

}

//Az Events adatszerkezet tesztje kevesebb mint 5 elemre.
int testEvents()
{

}

//Az Events adatszerkezet tesztje több mint 5 elemre.
int testEventsMax()
{
    
}