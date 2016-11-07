/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
    Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetet tartalmazó fejléc.
*/

#ifndef VISITOR_H
#define VISITOR_H

#include <time.h>

//A látogatókat modellező adatszerkezet
/*
+--------------------------------+
|             Visitor            |
|     +--------------------+     |
|     | int id             |     |
|     +--------------------+     |
|     +--------------------+     |
|     | char* name         |     |
|     +--------------------+     |
|     +--------------------+     |
|     | char* mail         |     |
|     +--------------------+     |
|     +--------------------+     |
|     | time_t date        |     |
|     +--------------------+     |
|                                |
+--------------------------------+ 
*/

typedef struct Visitor
{
    //A látogató sorszáma
    int id;
    //A látogató neve
    char name[100];
    //A látogató e-mail címe
    char email[100];
    //Regisztáció időpontja
    time_t date;
}Visitor;

//Új látogató létrehozása
struct Visitor* newVisitor(int, char*, char*, time_t);

//A Visitor típus destruktora
void freeVisitor(Visitor*);

#endif