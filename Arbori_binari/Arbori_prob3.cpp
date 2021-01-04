#include <fstream>
#include <iostream>

struct Arbore
{
    int info;
    Arbore *st, *dr;
}*rad;

std::ifstream f("arbore.txt");

void Parcurgere(Arbore *Nod, int Niv)
{
    if(Nod)
    {
        if(Niv == 0)
        {
            std::cout << Nod->info << " ";
            return;
        }
        else
        {
            Parcurgere(Nod->st, Niv - 1);
            Parcurgere(Nod->dr, Niv - 1);
        }
    }
}

Arbore* Creare()
{
    int nr;
    Arbore* d;
    f >> nr;
    if(nr)
    {
        d = new Arbore;
        d->info = nr;
        d->st = Creare();
        d->dr = Creare();
        return d;
    }
    else
        return NULL;
}

int main()
{
    int x;
    rad = Creare();
    f >> x;
    Parcurgere(rad, x - 1);
    return 0;
}
