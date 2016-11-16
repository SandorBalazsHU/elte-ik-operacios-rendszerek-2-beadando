/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
    Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetet tartalmazó fejléc.
*/

#ifndef TESTS_H
#define TESTS_H

    //A tesztfuttatás parancssori kapcsolójaz
    static const char* testConsoleParameter = "-t";

//Adatszerkezetek tesztjei

    /*A teszteket egyszerre futtató függvény.
    1-et ad vissza, ha megkapta a megfeleő parancsssori kapcsolót és 0-t ha nem.*/
    int test(int, char**);

    //A visitor adatszerkezet tesztje.
    int testVisitor();

    //Az Event adatszerkezet tesztje.
    int testEvent(int);

    //Az Events adatszerkezet tesztje.
    int testEvents(int, int);

//UI tesztek

    //A konzol színezését teszteli
    int consoleColorsTest();

#endif