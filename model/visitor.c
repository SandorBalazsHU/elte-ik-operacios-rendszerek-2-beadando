/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetethez tartozó fügvények.
*/

//mallochoz szügséges
#include <stdlib.h>
//strcpy-hez
#include <string.h>
#include <time.h>
#include "./Visitor.h"

//Új látogató létrehozása
struct Visitor* newVisitor(int id, char* name, char* mail, time_t date)
{
    struct Visitor* _this = malloc(sizeof(struct Visitor));
    _this->id=id;
    strcpy(_this->name, name);
    strcpy(_this->email, mail);
    _this->date=date;
    return _this;
}

//A Visitor típus destruktora
void freeVisitor(Visitor* visitor)
{
    free(visitor);
}