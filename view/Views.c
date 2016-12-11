/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A menünézetek megvalósításai.
    A nézetek részletezését lásd a Documentation.txt-ben.
*/
#include <unistd.h>
#include "Views.h"
#include "ConsoleIO.h"
#include "../model/Events.h"

int View1(Events* events)
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
        case '1' : View2(events);
        break;
        case '2' : View3();
        break;
        case '3' : return 0;
        break;
        default : errorMessage("Hiba a menüben!\n" );
    }
}

int View2(Events* events)
{
    clearScrean();
    printf("\n" );
    printIntro();
    printHeader("Jelentkezés");
    if(events->size > 0)
    {
        printEvents(events);

        _clearInputBuffer();
        int inputLimit = 200;
        char* name = readFromConsole("Név", inputLimit);
        char* email = readFromConsole("E-mail", inputLimit);
        char* eventID = readFromConsole("A választott rendezvény száma", inputLimit);

        char* subMenu[1];
        subMenu[0] = "Mentés              ";
        subMenu[1] = "Mégse               ";
        printMenu(subMenu, 2);

        char selectedMainMenuitem = menuGenerator("12");

        switch(selectedMainMenuitem)
        {
            case '1' :
                printMessage("Jelentkezésed elmentettük!");
                sleep(sleepTime);
                View1(events);
            break;
            case '2' : 
                View1(events);
            break;
            default : errorMessage("Hiba a menüben!\n" );
        }
    }
    else
    {
        printMessage("Nincsenek események!");
        sleep(sleepTime);
        View1(events);
    }
}

int View3()
{
    clearScrean();
    printIntro();
    errorMessage("Hiba a menüben!\n");
}