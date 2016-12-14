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

int view1(Events* events, FILE* datafile)
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
        case '1' : view2(events, datafile);
        break;
        case '2' : view3(events, datafile);
        break;
        case '3' : return 0;
        break;
        default : errorMessage("Hiba a menüben!\n" );
    }
}

void view2(Events* events, FILE* datafile)
{
    clearScrean();
    printIntro();
    printHeader("Jelentkezés");
    if(events->size > 0)
    {
        printEvents(events);

        _clearInputBuffer();
        char name[100];
        readFromConsole(name, "Név");
        char email[100];
        readFromConsole(email, "E-mail");
        int eventID = readIntFromConsole("A választott rendezvény száma");

        char* subMenu[1];
        subMenu[0] = "Mentés              ";
        subMenu[1] = "Mégse               ";
        printMenu(subMenu, 2);

        char selectedMainMenuitem = menuGenerator("12");

        switch(selectedMainMenuitem)
        {
            case '1' :
                addVisitorToEvent(getEventFromEventsById(events, eventID-1), newVisitor(name, email, getDate()));
                eventsWriterForBinFiles(events, datafile);
                printMessage("Jelentkezésed elmentettük!");
                sleep(sleepTime);
                view1(events, datafile);
            break;
            case '2' : view1(events, datafile);
            break;
            default : errorMessage("Hiba a menüben!\n" );
        }
    }
    else
    {
        printMessage("Nincsenek események!");
        sleep(sleepTime);
        view1(events, datafile);
    }
}

void view3(Events* events, FILE* datafile)
{
    clearScrean();
    printIntro();
    printHeader("Adminisztráció");

    char* subMenu[4];
    subMenu[0] = "Vendéglista         ";
    subMenu[1] = "Rendezvényszervezés ";
    subMenu[2] = "Rendezvénytörlés    ";
    subMenu[3] = "Vissza              ";
    printMenu(subMenu, 4);

    char selectedMainMenuitem = menuGenerator("1234");

    switch(selectedMainMenuitem)
    {
        case '1' : view4(events, datafile);
        break;
        case '2' : view5(events, datafile);
        break;
        case '3' : view6(events, datafile);
        break;
        case '4' : view1(events, datafile);
        break;
        default : errorMessage("Hiba a menüben!\n" );
    }
}

void view4(Events* events, FILE* datafile)
{
    clearScrean();
    printIntro();
    printHeader("Vendéglista");
    if(events->size > 0)
    {
        printEvents(events);

        _clearInputBuffer();
        int id = readIntFromConsole("Mely rendezvény vendéglistályát szerené látni (ID)");
        Event* event = getEventFromEventsById(events, id-1);

        char* subMenu[1];
        subMenu[0] = "Listáz              ";
        subMenu[1] = "Vissza              ";
        printMenu(subMenu, 2);

        char selectedMainMenuitem = menuGenerator("12");

        switch(selectedMainMenuitem)
        {
            case '1' : view7(events, event, datafile);
            break;
            case '2' : view3(events, datafile);
            break;
            default : errorMessage("Hiba a menüben!\n" );
        }
    }
    else
    {
        printMessage("Nincsenek események!");
        sleep(sleepTime);
        view1(events, datafile);
    }
}
void view5(Events* events, FILE* datafile)
{
    clearScrean();
    printIntro();
    printHeader("Rendezvényszervezés");
    _clearInputBuffer();

    char name[100];
    readFromConsole(name, "A létrehozandó rendezvény veve");
    char* subMenu[1];
    subMenu[0] = "Mentés              ";
    subMenu[1] = "Mégse               ";
    printMenu(subMenu, 2);

    char selectedMainMenuitem = menuGenerator("12");

    switch(selectedMainMenuitem)
    {
        case '1' : 
            eventsWriterForBinFiles(addEventToEvents(events, newEvent(name)), datafile);
            view3(events, datafile);
        break;
        case '2' : view3(events, datafile);
        break;
        default : errorMessage("Hiba a menüben!\n" );
    }
}
void view6(Events* events, FILE* datafile)
{
    clearScrean();
    printIntro();
    printHeader("Rendezvénytörlés");
    if(events->size > 0)
    {
        printEvents(events);

        _clearInputBuffer();
        int id = readIntFromConsole("A törölni kívánt rendezvény ID-ja");

        char* subMenu[1];
        subMenu[0] = "Törlés              ";
        subMenu[1] = "Mégse               ";
        printMenu(subMenu, 2);

        char selectedMainMenuitem = menuGenerator("12");

        switch(selectedMainMenuitem)
        {
            case '1' : 
                eventsWriterForBinFiles(deleteEventFromEventsById(events, id-1), datafile);
                view3(events, datafile);
            break;
            case '2' : view3(events, datafile);
            break;
            default : errorMessage("Hiba a menüben!\n" );
        }
    }
    else
    {
        printMessage("Nincsenek események!");
        sleep(sleepTime);
        view1(events, datafile);
    }
}

void view7(Events* events, int eventId FILE* datafile)
{
    clearScrean();
    printIntro();
    printHeader("Vendéglista");
    printVisitors(getEventFromEventsById(events, eventId));

    char* subMenu[4];
    subMenu[0] = "Vendégmódosítás     ";
    subMenu[1] = "Vendégtörlés        ";
    subMenu[2] = "Mentés              ";
    subMenu[3] = "Vissza              ";
    printMenu(subMenu, 4);

    char selectedMainMenuitem = menuGenerator("1234");

    switch(selectedMainMenuitem)
    {
        case '1' : view8(events, datafile);
        break;
        case '2' : view9(events, datafile);
        break;
        case '3' : view4(events, datafile);
        break;
        case '4' : view4(events, datafile);
        break;
        default : errorMessage("Hiba a menüben!\n" );
    }
}

void view8(Events* events, FILE* datafile)
{

}

void view9(Events* events, FILE* datafile)
{

}