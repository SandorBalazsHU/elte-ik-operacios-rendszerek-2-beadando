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
#include "../model/Event.h"
#include "../model/Events.h"

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
	printf("%s%s +---------------------------------------------------------+%s\n",spacer, FontGreen, ColorClear);
	printf("+%s%s|  \"King of Stands\" elektronikus látogatói nyilvántartás  |%s%s+\n", line, FontGreen, ColorClear, line);
	printf("%s%s +---------------------------------------------------------+%s\n",spacer, FontGreen, ColorClear);
}

//A menü kirajzolása
void printMenu(char** menuItems, int menuItemsNumber)
{
	int i;
	for(i = 0; i < menuItemsNumber; ++i)
	{
	printf("          +--------------------+ \n");
	printf("      %s%i.)%s |%s| \n", FontGreen, (i+1), ColorClear, menuItems[i]);
	printf("          +--------------------+ \n");
	}
	printf("      %s+%s Valassz funkciot: ", FontGreen, ColorClear);
}

/*A menük logikája
  Tetszőleges menü geráltatható vele.
  Meg kell adni egy karaktertömböt amiben egy karakter egy heles
  választási lehetőséget jelent a menüben.*/
char menuGenerator(char* menuItems)
{
	char selectedMenuItem = '~';
	short int state = 0;
	short int isCorrect = 0;
	int i;
	while( isCorrect == 0 )
	{
		if ((selectedMenuItem != '~') && ( selectedMenuItem != '\n') && ( state == 0))
		{
			printf("      %s+%s Hibás érték! Add meg újra: ", FontGreen, ColorClear);
			state++;
		}
		selectedMenuItem = getchar();

		if(selectedMenuItem == '\n') state = 0;

		for(i = 0; i < strlen(menuItems); ++i)
		{
			if(menuItems[i] == selectedMenuItem)
			{
				isCorrect = 1;
				break;
			}
		}
	}
	return selectedMenuItem;
}

void printEvents(Events* events)
{
	int i;
	int fullWidth = 0;
	int fullNameWidth = 0;

	for(i=0; i<events->size; ++i)
	{
		int len = _strlenForUnicode(events->eventsArray[i]->name);
		if(len>fullNameWidth) fullNameWidth = len;
	}
	fullWidth = (int) fullNameWidth + 16;

	int spacerWidth = (int) (getConsoleWindowWidth() - fullWidth)/2;
	char spacer[spacerWidth+2];
	spacerGenerator(spacer, ' ', spacerWidth);

	char nameLine[fullNameWidth+4];
	spacerGenerator(nameLine, '-', (int) (fullNameWidth+2));
	
	printf("%s%s+%s-----%s+%s%s%s+%s-----%s+%s\n", spacer, FontGreen, ColorClear, FontGreen, ColorClear, nameLine, FontGreen, ColorClear, FontGreen, ColorClear);
	for(i=0; i<events->size; ++i)
	{
		Event* tmpEvent = events->eventsArray[i];
		printf("%s| %i   | %s | %i   |\n", spacer, (int) (tmpEvent->id + 1), tmpEvent->name, tmpEvent->size);
		printf("%s%s+%s-----%s+%s%s%s+%s-----%s+%s\n", spacer, FontGreen, ColorClear, FontGreen, ColorClear, nameLine, FontGreen, ColorClear, FontGreen, ColorClear);
	}
}

void printVisitors(Events* events, int eventID)
{
	int i;
	int fullWidth = 0;
	int fullNameWidth = 0;
	int fullEmailWidth = 0;

	for(i=0; i<events->eventsArray[eventID]->size; ++i)
	{
		int len = _strlenForUnicode(events->eventsArray[eventID]->visitorArray[i]->name);
		if(len>fullNameWidth) fullNameWidth = len;
	}

	for(i=0; i<events->eventsArray[eventID]->size; ++i)
	{
		int len = _strlenForUnicode(events->eventsArray[eventID]->visitorArray[i]->email);
		if(len>fullEmailWidth) fullEmailWidth = len;
	}

	fullWidth = (int) fullNameWidth + fullEmailWidth + 30;

	int spacerWidth = (int) (getConsoleWindowWidth() - fullWidth)/2;
	char spacer[spacerWidth+2];
	spacerGenerator(spacer, ' ', spacerWidth);

	char nameLine[fullNameWidth+4];
	spacerGenerator(nameLine, '-', (int) (fullNameWidth+2));
	char emailLine[fullEmailWidth+4];
	spacerGenerator(emailLine, '-', (int) (fullEmailWidth+2));
	
	printf("%s%s+%s A/Az [%s] eseményre jelentkezett vendégek: \n", spacer, FontGreen, ColorClear, events->eventsArray[eventID]->name);
	printf("%s%s+%s-----%s+%s%s%s+%s%s%s+%s--------------------%s+%s\n", spacer, FontGreen, ColorClear, FontGreen, ColorClear,  nameLine, FontGreen, ColorClear, emailLine, FontGreen, ColorClear, FontGreen, ColorClear);
	for(i=0; i<events->eventsArray[eventID]->size; ++i)
	{
		Visitor* tmpVisitor = events->eventsArray[eventID]->visitorArray[i];
		printf("%s| %i   | %s | %s | ", spacer, (int) (tmpVisitor->id + 1), tmpVisitor->name, tmpVisitor->email);
		datePrintOut(tmpVisitor->date);
		printf(" |\n");
		printf("%s%s+%s-----%s+%s%s%s+%s%s%s+%s--------------------%s+%s\n", spacer, FontGreen, ColorClear, FontGreen, ColorClear,  nameLine, FontGreen, ColorClear, emailLine, FontGreen, ColorClear, FontGreen, ColorClear);
	}
}

/*
	Megadott hosszúságú sort generál egy karakterből és a hosszából.
	FIGYELEM: A szügségesnél 2-vel nagyobb tömböt kell deklarálni számára.
	-Paraméterek: +
				  |-spacer: A tömb amivel dolgozni fog (Mérete N+2 legyen!)
				  |-c: A karakter amiből a sort geneálja
				  |-n: A kívánt sor hossza.
*/
void spacerGenerator(char* spacer, char c, int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		spacer[i] = c;
	}
	spacer[n+1] = '\0';
	spacer[n+2] = '\0';
}

int _strlenForUnicode(char* s)
{
   int i = 0, j = 0;
   while (s[i]) {
     if ((s[i] & 0xc0) != 0x80) j++;
     i++;
   }
   return j;
}
