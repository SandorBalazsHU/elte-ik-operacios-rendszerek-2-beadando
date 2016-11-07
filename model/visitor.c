/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetethez tartozó fügvények.
*/

//Új látogató létrehozása
struct Visitor* newVisitor(int id, char* name, char* mail, time_t date)
{
    struct Visitor* _this = malloc(sizeof(struct Visitor));
    this->id=id;
    strcpy(_this->name, name);
    strcpy(_this->mail, mail);
    _this->date=date;
    return _this;
}

//A Visitor típus destruktora
void freeVisitor(Visitor* visitor)
{
    free(visitor);
}