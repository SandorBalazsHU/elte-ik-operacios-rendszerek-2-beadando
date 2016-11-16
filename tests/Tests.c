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
#include "../view/ConsoleIO.h"
#include "../model/Events.h"
#include "../model/Event.h"
#include "../model/Visitor.h"
#include "../controller/File.h"

//A teszteket egyszerre futtató függvény.
int test(int argc, char** argv)
{
    if(argc > 1)
    {
        if(strcmp(argv[1], testConsoleParameter) == 0)
        {
            //A konzol színezését teszteli
            consoleColorsTest();

            //A visitor adatszerkezet tesztje.
            testVisitor();

            //Az Event adatszerkezet tesztje kevesebb mint 5 elemre.
            testEvent( 3 );

            //Az Event adatszerkezet tesztje több mint 5 elemre.
            testEvent( 10 );

            //Az Events adatszerkezet tesztje kevesebb mint 5 elemre.
            testEvents( 3, 3 );

            //Az Events adatszerkezet tesztje több mint 5 elemre.
            testEvents( 8, 3 );

            return 1;
        }
    }
    return 0;
}

//A visitor adatszerkezet tesztje.
int testVisitor()
{
    printf("\n testVisitor \n");

    Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
    printf("     newVisitor - %sOK%s\n", FontGreen, ColorClear);

    freeVisitor(visitor1);
    printf("     freeVisitor - %sOK%s\n", FontGreen, ColorClear);
}

//Az Event adatszerkezet tesztje.
int testEvent(int n)
{
    printf("\n+ testEvent - %i\n", n);
    Event* event1 = newEvent(0,"event1");
    printf("     + newEvent - %sOK%s\n", FontGreen, ColorClear);
    int i;
        for(i = 0; i < n; ++i)
        {
            Visitor* visitor = newVisitor(i, "visitor", "visitor@mail.org", getDate());
            printf("          + newVisitor %i - %sOK%s\n", (i+1), FontGreen, ColorClear);
            addVisitorToEvent(event1, visitor);
            printf("          + addVisitorToEvent %i - %sOK%s\n", (i+1), FontGreen, ColorClear);
        }
    int getVisitorsNumberFromEventTestValue = getVisitorsNumberFromEvent(event1);
    if(getVisitorsNumberFromEventTestValue == n)
    {
        printf("     - getVisitorsNumberFromEvent= %i == %i - %sOK%s\n", getVisitorsNumberFromEventTestValue, n, FontGreen, ColorClear);
    }
    else
    {
        printf("     - getVisitorsNumberFromEvent= %i =/= %i - %sFALSE%s\n", getVisitorsNumberFromEventTestValue, n, FontRed, ColorClear);
    }
    freeEvent(event1);
    printf("     - freeEvent - %sOK%s\n", FontGreen, ColorClear);
}

//Az Events adatszerkezet tesztje.
int testEvents(int n, int m)
{
    printf("\n+ testEvents - %i, %i\n", n, m);

    Events* events = newEvents();
    printf("     + newEvents - %sOK%s \n", FontGreen, ColorClear);

    int i;
    for(i = 0; i < n; ++i)
    {
        Event* event = newEvent(i,"event");
        printf("          + newEvent %i - %sOK%s \n", (i+1), FontGreen, ColorClear);
        int j;
        for(j = 0; j < m; ++j)
        {
            Visitor* visitor = newVisitor(j, "visitor", "visitor@mail.org", getDate());
            printf("               + newVisitor %i - %sOK%s\n", (j+1), FontGreen, ColorClear);
            addVisitorToEvent(event, visitor);
            printf("               + addVisitorToEvent %i - %sOK%s\n", (j+1), FontGreen, ColorClear);
        }
        addEventToEvents(events, event);
        printf("          addEventToEvents %i - %sOK%s \n", (i+1), FontGreen, ColorClear);
    }

    freeEvents(events);
    printf("     + freeEvents - %sOK%s \n", FontGreen, ColorClear);
}

int consoleColorsTest()
{
    printf("\n+ consoleColorsTest");
    printf("\n|      %s%sFontBlack%s",     FontBackWhite, FontBlack,   ColorClear);
    printf("\n|      %sFontRed%s",         FontRed,       ColorClear);
    printf("\n|      %sFontGreen%s",       FontGreen,     ColorClear);
    printf("\n|      %sFontYellow%s",      FontYellow,    ColorClear);
    printf("\n|      %sFontPurple%s",      FontPurple,    ColorClear);
    printf("\n|      %sFontCyan%s",        FontCyan,      ColorClear);
    printf("\n|      %sFontWhite%s",       FontWhite,     ColorClear);
    printf("\n+ consoleColorsTest");
    printf("\n|      %sFontBackBlack%s",   FontBackBlack, ColorClear);
    printf("\n|      %sFontBackRed%s",     FontBackRed,   ColorClear);
    printf("\n|      %sFontBackGreen%s",   FontBackGreen, ColorClear);
    printf("\n|      %sFontBackYellow%s",  FontBackYellow,ColorClear);
    printf("\n|      %sFontBackBlue%s",    FontBackBlue,  ColorClear);
    printf("\n|      %sFontBackPurple%s",  FontBackPurple,ColorClear);
    printf("\n|      %sFontBackCyan%s",    FontBackCyan,  ColorClear);
    printf("\n|      %s%sFontBackWhite%s", FontBlack,   FontBackWhite, ColorClear);
}