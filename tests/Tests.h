/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
    Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetet tartalmazó fejléc.
*/

#ifndef VISITOR_H
#define VISITOR_H

    //A teszteket egyszerre futtató függvény.
    int test();

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