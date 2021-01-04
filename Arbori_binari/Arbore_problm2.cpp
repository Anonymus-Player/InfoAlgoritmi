#include <iostream>

struct Arbore
{
    int info;
    Arbore *st, *dr;
}*rad;

void Parcurgere_inordine(Arbore *nod)
{
    if(nod)
    {
        Parcurgere_inordine(nod->st);
        std::cout << nod->info << " ";
        Parcurgere_inordine(nod->dr);
    }
}

void Parcurgere_preordine(Arbore* nod)
{
    if(nod)
    {
        std::cout << nod->info << " ";
        Parcurgere_preordine(nod->st);
        Parcurgere_preordine(nod->dr);
    }
}

void Parcurgere_postordine(Arbore* nod)
{
    if(nod)
    {
        Parcurgere_postordine(nod->st);
        Parcurgere_postordine(nod->dr);
        std::cout << nod->info << " ";
    }
}

Arbore* Creere()
{
    int nr;
    Arbore *d;
    std::cout << "Nr de ordine: ";
    std::cin >> nr;
    if(nr)
    {
        d = new Arbore;
        d->info = nr;
        d->st = Creere();
        d->dr = Creere();
        return d;
    }
    else
        return NULL;
}

int main()
{
    rad = Creere();
    std::cout << "\nParcurgere Inordine:\n";
    Parcurgere_inordine(rad);
    std::cout << "\nParcurgere Preordine:\n";
    Parcurgere_preordine(rad);
    std::cout << "\nParcurgere Postordine:\n";
    Parcurgere_postordine(rad);
    std::cout << "\n";
    return 0;
}