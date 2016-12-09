/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A menünézetek megvalósításai.
    A nézetek részletezését lásd a Documentation.txt-ben.
*/

#include "ConsoleIO.h"
#include "Views.h"

int View1()
{
    clearScrean();
    printIntro();

    char* mainMenu[3];
    mainMenu[0] = "Jelentkezés         ";
    mainMenu[1] = "Adminisztráció      ";
    mainMenu[2] = "Kilépés             ";
    printMenu(mainMenu, 3);

    char selectedMainMenuitem = menuGenerator("123");

    switch(selectedMainMenuitem)
    {
        case '1' :
            View2();
        break;
        case '2' :
            View3();
        break;
        case '3' :
            return 0;
        break;
        default :
            printf("HIBA!\n" );
    }
}

int View2()
{
    clearScrean();
    printIntro();
    printf("Wiew2\n");
}

int View3()
{
    clearScrean();
    printIntro();
    printf("Wiew3\n");
}