/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A menünézetek megvalósításai.
    A nézetek részletezését lásd a Documentation.txt-ben.
*/
#ifndef VIEWS_H
#define VIEWS_H

#include "../model/Events.h"

    #define sleepTime 2
    int  view1(Events*, FILE*);
    void view2(Events*, FILE*);
    void view3(Events*, FILE*);
    void view4(Events*, FILE*);
    void view5(Events*, FILE*);
    void view6(Events*, FILE*);
    void view7(Events*, int, FILE*);
    void view8(Events*, FILE*);
    void view9(Events*, FILE*);

#endif