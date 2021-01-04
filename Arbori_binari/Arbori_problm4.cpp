#include <iostream>
#include <fstream>
#include <memory.h>
#include <csignal>

struct Arbore
{
    int info;
    Arbore *st, *dr;
};

Arbore *rad;
int t[20], n, i, j;
std::ifstream f("vectati.txt");

void Citire()
{
    n = 0;
    while(f >> t[++n]);
}

Arbore* Adaugare(int nr)
{
    Arbore *Nod;
    Nod = new Arbore;
    Nod->info = nr;
    Nod->st = Nod->dr = NULL;
    return Nod;
}

void Reconstruire(Arbore *Nod, int pos)
{
    int x, y;
    x = y = 0;
    for(i = 1; i <= n; i++)
    {
        if(t[i] == pos)
        {
            if(x != 0)
                y = i;
            else
                x = i;
        }
    }
    if(x != 0 && y != 0)
    {
        if(x < y)
        {
            Nod->st = Adaugare(x);
            Nod->dr = Adaugare(y);
            Reconstruire(Nod->st, x);
            Reconstruire(Nod->dr, y);
        }
        else
        {
            Nod->st = Adaugare(y);
            Nod->dr = Adaugare(x);
            Reconstruire(Nod->st, y);
            Reconstruire(Nod->dr, x);
        }
    }
    else if(x != 0)
    {
        Nod->st = Adaugare(x);
        Reconstruire(Nod->st, x);
    }
}

void Start()
{
    for(i = 1; i <= n; i++)
        if(t[i] == 0)
        {
            rad = Adaugare(i);
            Reconstruire(rad, i);
        }
}

void Parcurgere_preordine(Arbore *Nod)
{
    if(Nod)
    {
        std::cout << Nod->info << " ";
        Parcurgere_preordine(Nod->st);
        Parcurgere_preordine(Nod->dr);
    }
}

int main()
{
    Citire();
    Start();
    Parcurgere_preordine(rad);
    std::cout << "\n";
    return 0;
}
