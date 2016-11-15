/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A konzolműveletek megvalósítása.
*/
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#include "./ConsoleIO.h"

//Képernyő töröl
void clearScrean()
{
    int r = system("clear");
}

time_t getDate()
{
    return time(NULL);
}

//Kiírja a saját dátum reprezentációt a képernyőre
void datePrintOut(time_t date)
{
	struct tm tm = *localtime(&date);
	printf("%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

//Megadja a képernyő jelenlegi szélességét
int getConsoleWindowWidth()
{
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}

//Kiírja a köszöntő szöveget
void printIntro()
{
	printf("\n");
	int i, position = (int) (getConsoleWindowWidth()/2)-31;
	char spacer[position+1];
	char line[position+1];
        spacer[position+1] = '\0';
	line[position+1] = '\0'; 
	for(i = 0; i < position; ++i)
	{
		spacer[i] = ' ';
		line[i] = '-'; 
	}
	printf("%s\x1b[32m +---------------------------------------------------------+\x1b[0m\n",spacer);
	printf("+%s\x1b[32m|  \"King of Stands\" elektronikus látogatói nyilvántartás  |\x1b[0m%s+\n",line,line);
	printf("%s\x1b[32m +---------------------------------------------------------+\x1b[0m\n",spacer);
}

//A főmeü kirajzolása
void printMainMenu()
{
	printf("          +-------------------+ \n");
	printf("      \x1b[32m1.)\x1b[0m | Jelentkezés! | \n");
	printf("          +-------------------+ \n");
	printf("          +-------------------+ \n");
	printf("      \x1b[32m2.)\x1b[0m | Adminisztráció    | \n");
	printf("          +-------------------+ \n");
	printf("          +-------------------+ \n");
	printf("      \x1b[32m3.)\x1b[0m | Kilépés           | \n");
	printf("          +-------------------+ \n");
	printf("      \x1b[32m+\x1b[0m Valassz funkciot: ");
}

//A menük logika
char mainMenu()
{
	char selectedMenuPoint = ' ';
	while( !((selectedMenuPoint == '1') || (selectedMenuPoint == '2') || (selectedMenuPoint == '3')) )
	{
		if ((selectedMenuPoint != ' ') && ( selectedMenuPoint != '\n')) printf("      \x1b[32m+\x1b[0m Hibas ertek! Add meg újra: ");
		selectedMenuPoint = getchar();
	}
	return selectedMenuPoint;
}