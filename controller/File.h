/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A fájlkezelésért felelős függvények
*/

#ifndef FILE_H
#define FILE_H
    #include <stdio.h>
    #include "../model/Events.h"
    #include "../model/Event.h"
    #include "../model/Visitor.h"

    void eventsWriterForBinFiles(Events*, FILE*);
    void eventWriterForBinFiles(Event*, FILE*);
    void visitorWriterForBinFiles(Visitor*, FILE*);
    Events* eventsReaderForBinFiles(FILE* f);
    Event* eventReaderForBinFiles(FILE*, int);
    Visitor* visitorReaderForBinFiles(FILE*, int);
    FILE* openBinFileForRead(const char*);
    FILE* openBinFileForWrite(const char*);
    int getFileSize(FILE* f);

#endif