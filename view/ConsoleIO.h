/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A konzolműveletek megvalósítása.
*/
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

    /*A menük logikája
      Tetszőleges menü geráltatható vele.
      Meg kell adni egy karaktertömböt amiben egy karakter egy heles
      választási lehetőséget jelent a menüben.*/
    char menuGenerator(char*);

#endif