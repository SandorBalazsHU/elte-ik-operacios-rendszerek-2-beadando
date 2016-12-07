/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    Az eseményeket reprezentáló adatszerkezetet tartalmazó fejléc.
*/

#ifndef EVENT_H
#define EVENT_H

    #include <stdio.h>
    #include "./Visitor.h"

    //A eseményt modellező adatszerkezet
    /*
    +------------------------+
    |          Event         |
    | +--------------------+ |
    | |    int id          | |
    | +--------------------+ |
    | +--------------------+ |
    | |    char* name      | |
    | +--------------------+ |
    | +--------------------+ |
    | |    int size        | |
    | +--------------------+ |
    | +--------------------+ |
    | |    int _realSize   | |
    | +--------------------+ |
    | +--------------------+ |            +--------------------+
    | |Visitor** eventArray| |===========>|    eventArray[]    |
    | +--------------------+ |            | +----------------+ |              +----------------+
    +------------------------+            | |     Visitor*   | | ===========> |     Visitor    |
                                        | +----------------+ |              +----------------+
                                        | +----------------+ |              +----------------+
                                        | |     Visitor*   | | ===========> |     Visitor    |
                                        | +----------------+ |              +----------------+
                                        | +----------------+ |              +----------------+
                                        | |     Visitor*   | | ===========> |     Visitor    |
                                        | +----------------+ |              +----------------+
                                        |         ...        |                      ...
                                        +--------------------+
    */

    typedef struct Event
    {
        //A rendezvény sorszáma
        int id;
        //A rendezvény neve
        char name[100];
        //Felvett látogatók száma
        int size;
        //A tároló tömb valós mérete
        int _realSize;
        //Az látogatkra mutató pointerek tömbje
        Visitor** visitorArray;
    }Event;

    //Az alapértelmezett tároló tömb mérete
    static const int defaultArraySize = 5;

    //Új esemény létrehozásához
    struct Event* newEvent(int, char*);

    //Látogató hozzáadását teszi lehetőve az eseményhez
    /*	Ha a tömb betelt, akkor dupla méretűt deklarálunk, átmásoljuk az adatokat
    és a régit töröljük a C++ STD Vector mintájára.*/
    int addVisitorToEvent(Event*, Visitor*);

    //Látogató törlése az eseményről
    int deleteVisitorFromEvent(Event*, Visitor*);

    //Index szerinti keresés a látogatók között
    struct Visitor* getVisitorFromEventById(Event*, int);

    //Visszaadja a látogatók számát.
    int getVisitorsNumberFromEvent(Event*);

    /*Az Event típus destruktora
    Kell destrukfor, mivel az eventArray külön álló egységet képez a memóriában
    Törli a tömb által mutatott elemeket is!*/
    void freeEvent(Event*);

#endif