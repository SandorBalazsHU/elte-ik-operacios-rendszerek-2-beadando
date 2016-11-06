#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include <time.h>

//Képernyő töröl
void clearScrean();

//Lekérdezi a dátumot
time_t getDate();

//Kiírja a saját dátum reprezentációt a képernyőre
void datePrintOut(time_t date);

//Megadja a képernyő jelenlegi szélességét
int getConsoleWindowWidth();

//Kiírja a köszöntő szöveget
void printIntro();

//A főmeü kirajzolása
void printMainMenu();

#endif