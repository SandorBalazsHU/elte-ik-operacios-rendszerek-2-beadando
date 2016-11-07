/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
    Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetet tartalmazó fejléc.
*/

#ifndef VISITOR_H
#define VISITOR_H

    //A tesztfuttatás parancssori kapcsolója
    const char* testConsoleParameter = "-t";

    /*A teszteket egyszerre futtató függvény.
    1-et ad vissza, ha megkapta a megfeleő parancsssori kapcsolót és 0-t ha nem.*/
    int test(int, char**);

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

#endif