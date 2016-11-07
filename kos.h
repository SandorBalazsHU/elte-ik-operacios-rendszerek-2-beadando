/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    Egy egységes API-t biztosít. Így csak ezt az egy fejlécet kell használni.
*/

//A konzolkezelő függvények gyűjteménye
#include "./view/ConsoleIO.h"

//Az eseménytároló adatszerkezet és a hozzá tartozó függvények gyűjteménye.
#include "./model/Events.h"

/*Az eseményt reprezentáló szerkezet és a hozzá tartozó függvények gyűjteménye.
Ez tárolja a látogatókat is.*/
#include "./model/Event.h"

//A látogatókat reprezentáló szerkezet és a hozzá tartozó függvények gyűjteménye.
#include "./model/Visitor.h"

//A fájlműveletekért felelős függvények gyűjteménye
#include "./controller/File.h"

//A tesztfüggvények gyűjteménye
#include "./tests/Tests.h"