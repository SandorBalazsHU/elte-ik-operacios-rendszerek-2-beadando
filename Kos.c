/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A program belépési pntja.
*/
#include <stdio.h>
#include "./Kos.h"

int main(int argc, char** argv)
{
    //Tesztek futtatása megfeleő argumentum esetén.
    if(test(argc, argv))
    {
        return 0;
    }

    FILE* datafile = openBinFileForRead(_dataFileName);
    Events* events = eventsReaderForBinFiles(datafile);
    fclose(datafile);

    //Ha nem a teszteket futtatjuk akkor kitesszük az első nézetet.
    View1(events);

    return 0;
}