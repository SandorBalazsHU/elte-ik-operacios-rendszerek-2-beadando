/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetethez tartozó fügvények.
*/

#include <string.h>
#include <stdio.h>
#include "./Tests.h"
#include "./view/ConsoleIO.h"
#include "./model/Events.h"
#include "./model/Event.h"
#include "./model/Visitor.h"
#include "./controller/File.h"

//A teszteket egyszerre futtató függvény.
int test(int argc, char** argv)
{
    if(argc > 1)
    {
        if(strcmp(argv[1], testConsoleParameter))
        {
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

            return 1;
        }
    }
    return 0;
}

//A visitor adatszerkezet tesztje.
int testVisitor()
{
    printf("\n testVisitor \n");

    Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
    printf("     newVisitor - OK\n");

    freeVisitor(visitor1);
    printf("     freeVisitor - OK\n");
}

//Az Event adatszerkezet tesztje kevesebb mint 5 elemre.
int testEvent()
{
    printf("\n testEvent \n");

    Event* event1 = newEvent(0,"event1");
    printf("newEvent - OK\n");

        Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
        printf("     newVisitor1 - OK\n");

        addVisitorToEvent(event1, visitor1);
        printf("     addVisitorToEvent1 - OK\n");

        Visitor* visitor2 = newVisitor(1, "visitor2", "visitor2@mail.org", getDate());
        printf("     newVisitor2 - OK\n");

        addVisitorToEvent(event1, visitor2);
        printf("     addVisitorToEvent2 - OK\n");

        Visitor* visitor3 = newVisitor(2, "visitor3", "visitor3@mail.org", getDate());
        printf("     newVisitor3 - OK\n");

        addVisitorToEvent(event1, visitor3);
        printf("     addVisitorToEvent3 - OK\n");

    freeEvent(event1);
    printf("     freeEvent - OK\n");
}

//Az Event adatszerkezet tesztje több mint 5 elemre.
int testEventMax()
{
    printf("\n testEventMax \n");

    Event* event1 = newEvent(0,"event1");
    printf("     newEvent1 - OK\n");

        Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
        printf("          newVisitor1 - OK\n");

        addVisitorToEvent(event1, visitor1);
        printf("               addVisitorToEvent1 - OK\n");

        Visitor* visitor2 = newVisitor(1, "visitor2", "visitor2@mail.org", getDate());
        printf("          newVisitor2 - OK\n");

        addVisitorToEvent(event1, visitor2);
        printf("               addVisitorToEvent2 - OK\n");

        Visitor* visitor3 = newVisitor(2, "visitor3", "visitor3@mail.org", getDate());
        printf("          newVisitor3 - OK\n");

        addVisitorToEvent(event1, visitor3);
        printf("               addVisitorToEvent3 - OK\n");

        Visitor* visitor4 = newVisitor(3, "visitor4", "visitor4@mail.org", getDate());
        printf("          newVisitor4 - OK\n");

        addVisitorToEvent(event1, visitor4);
        printf("               addVisitorToEvent4 - OK\n");

        Visitor* visitor5 = newVisitor(4, "visitor5", "visitor5@mail.org", getDate());
        printf("          newVisitor5 - OK\n");

        addVisitorToEvent(event1, visitor5);
        printf("               addVisitorToEvent5 - OK\n");

        Visitor* visitor6 = newVisitor(5, "visitor6", "visitor6@mail.org", getDate());
        printf("          newVisitor6 - OK\n");

        addVisitorToEvent(event1, visitor6);
        printf("               addVisitorToEvent6 - OK\n");

        Visitor* visitor7 = newVisitor(6, "visitor7", "visitor7@mail.org", getDate());
        printf("          newVisitor7 - OK\n");

        addVisitorToEvent(event1, visitor7);
        printf("               addVisitorToEvent7 - OK\n");

        Visitor* visitor8 = newVisitor(7, "visitor8", "visitor8@mail.org", getDate());
        printf("          newVisitor8 - OK\n");

        addVisitorToEvent(event1, visitor8);
        printf("               addVisitorToEvent8 - OK\n");

    freeEvent(event1);
    printf("     freeEvent - OK\n");
}

//Az Events adatszerkezet tesztje kevesebb mint 5 elemre.
int testEvents()
{
    printf("\n testEvents \n");
    Events* events1 = newEvents();
        Event* event1 = newEvent(0,"event1");
            Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
            addVisitorToEvent(event1, visitor1);
            Visitor* visitor2 = newVisitor(1, "visitor2", "visitor2@mail.org", getDate());
            addVisitorToEvent(event1, visitor2);
            Visitor* visitor3 = newVisitor(2, "visitor3", "visitor3@mail.org", getDate());
            addVisitorToEvent(event1, visitor3);
        addEventToEvents(events1, event1);

        Event* event2 = newEvent(1,"event2");
            Visitor* visitor4 = newVisitor(3, "visitor4", "visitor4@mail.org", getDate());
            addVisitorToEvent(event2, visitor4);
            Visitor* visitor5 = newVisitor(4, "visitor5", "visitor5@mail.org", getDate());
            addVisitorToEvent(event2, visitor5);
            Visitor* visitor6 = newVisitor(5, "visitor6", "visitor6@mail.org", getDate());
            addVisitorToEvent(event2, visitor6);
        addEventToEvents(events1, event2);

        Event* event3 = newEvent(2,"event3");
            Visitor* visitor7 = newVisitor(6, "visitor7", "visitor7@mail.org", getDate());
            addVisitorToEvent(event3, visitor7);
            Visitor* visitor8 = newVisitor(7, "visitor8", "visitor8@mail.org", getDate());
            addVisitorToEvent(event3, visitor8);
            Visitor* visitor9 = newVisitor(8, "visitor9", "visitor9@mail.org", getDate());
            addVisitorToEvent(event3, visitor9);
        addEventToEvents(events1, event3);
}

//Az Events adatszerkezet tesztje több mint 5 elemre.
int testEventsMax()
{
    Events* events1 = newEvents();
        Event* event1 = newEvent(0,"event1");
            Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
            addVisitorToEvent(event1, visitor1);
            Visitor* visitor2 = newVisitor(1, "visitor2", "visitor2@mail.org", getDate());
            addVisitorToEvent(event1, visitor2);
            Visitor* visitor3 = newVisitor(2, "visitor3", "visitor3@mail.org", getDate());
            addVisitorToEvent(event1, visitor3);
        addEventToEvents(events1, event1);

        Event* event2 = newEvent(1,"event2");
            Visitor* visitor4 = newVisitor(3, "visitor4", "visitor4@mail.org", getDate());
            addVisitorToEvent(event2, visitor4);
            Visitor* visitor5 = newVisitor(4, "visitor5", "visitor5@mail.org", getDate());
            addVisitorToEvent(event2, visitor5);
            Visitor* visitor6 = newVisitor(5, "visitor6", "visitor6@mail.org", getDate());
            addVisitorToEvent(event2, visitor6);
        addEventToEvents(events1, event2);

        Event* event3 = newEvent(2,"event3");
            Visitor* visitor7 = newVisitor(6, "visitor7", "visitor7@mail.org", getDate());
            addVisitorToEvent(event3, visitor7);
            Visitor* visitor8 = newVisitor(7, "visitor8", "visitor8@mail.org", getDate());
            addVisitorToEvent(event3, visitor8);
            Visitor* visitor9 = newVisitor(8, "visitor9", "visitor9@mail.org", getDate());
            addVisitorToEvent(event3, visitor9);
        addEventToEvents(events1, event3);

        Event* event4 = newEvent(3,"event3");
            Visitor* visitor10 = newVisitor(9, "visitor10", "visitor10@mail.org", getDate());
            addVisitorToEvent(event4, visitor10);
            Visitor* visitor11 = newVisitor(10, "visitor11", "visitor11@mail.org", getDate());
            addVisitorToEvent(event4, visitor11);
            Visitor* visitor12 = newVisitor(11, "visitor12", "visitor12@mail.org", getDate());
            addVisitorToEvent(event4, visitor12);
        addEventToEvents(events1, event4);

        Event* event5 = newEvent(4,"event4");
            Visitor* visitor13 = newVisitor(12, "visitor13", "visitor13@mail.org", getDate());
            addVisitorToEvent(event5, visitor13);
            Visitor* visitor14 = newVisitor(13, "visitor14", "visitor14@mail.org", getDate());
            addVisitorToEvent(event5, visitor14);
            Visitor* visitor15 = newVisitor(14, "visitor15", "visitor15@mail.org", getDate());
            addVisitorToEvent(event5, visitor15);
        addEventToEvents(events1, event5);

        Event* event6 = newEvent(5,"event5");
            Visitor* visitor16 = newVisitor(15, "visitor16", "visitor16@mail.org", getDate());
            addVisitorToEvent(event6, visitor16);
            Visitor* visitor17 = newVisitor(16, "visitor17", "visitor17@mail.org", getDate());
            addVisitorToEvent(event6, visitor17);
            Visitor* visitor18 = newVisitor(17, "visitor18", "visitor18@mail.org", getDate());
            addVisitorToEvent(event6, visitor18);
        addEventToEvents(events1, event6);

        Event* event7 = newEvent(6,"event6");
            Visitor* visitor19 = newVisitor(18, "visitor19", "visitor19@mail.org", getDate());
            addVisitorToEvent(event6, visitor19);
            Visitor* visitor20 = newVisitor(19, "visitor20", "visitor20@mail.org", getDate());
            addVisitorToEvent(event6, visitor20);
            Visitor* visitor21 = newVisitor(20, "visitor21", "visitor21@mail.org", getDate());
            addVisitorToEvent(event6, visitor21);
        addEventToEvents(events1, event7);
    freeEvents(events1);
}