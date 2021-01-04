#include <iostream>

struct Arbore
{
    int info;
    Arbore *st, *dr;
}*rad, *d;

void Adaug(Arbore *nod, int nr)
{
    if(nr)
    {
        if(nod->st != NULL && nr < nod->info)
            Adaug(nod->st, nr);
        else if(nod->dr != NULL && nr > nod->info)
            Adaug(nod->dr, nr);
        else
        {
            if(nr < nod->info)
            {
                d = new Arbore;
                d->info = nr;
                d->dr = NULL;
                d->st = NULL;
                nod->st = d;
            }
            else if(nr > nod->info)
            {
                d = new Arbore;
                d->info = nr;
                d->dr = NULL;
                d->st = NULL;
                nod->dr = d;
            }
        }
    }
}

void Parcurgere_inordine(Arbore *nod)
{
    if(nod)
    {
        Parcurgere_inordine(nod->st);
        std::cout << nod->info << " ";
        Parcurgere_inordine(nod->dr);
    }
}

int Cautare(Arbore *nod, int nr)
{
    if(nod)
    {
        if(nod->st != NULL && nr < nod->info)
            Adaug(nod->st, nr);
        else if(nod->dr != NULL && nr > nod->info)
            Adaug(nod->dr, nr);
        else
            return 1;
    }
    return 0;
}

void Elim(Arbore *nod, int nr)
{
    if(nod)
    {
        if(nod->st->info == nr)
        {
            d = nod->st;
            if(d->dr == NULL && d->st == NULL)
            {
                delete d;
                nod->st = NULL;
            }
        }
        else if(nod->dr->info == nr)
        {
            d = nod->dr;
            if(d->dr == NULL && d->st == NULL)
            {
                delete d;
                nod->dr = NULL;
            }
        }
        else
        {
            if(nr < nod->info)
                Elim(nod->st, nr);
            else if(nr > nod->info)
                Elim(nod->dr, nr);
        }
    }
}

int main()
{
    char Input_flag;
    while(1)
    {
        std::cin >> Input_flag;
        switch(Input_flag)
        {
            case 'a':
            {
                int nr;
                std::cout << "Numar de ordine: ";
                std::cin >> nr;
                if(rad)
                    Adaug(rad, nr);
                else if(nr)
                {
                    rad = new Arbore;
                    rad->info = nr;
                    rad->st = NULL;
                    rad->dr = NULL;
                }
                break;
            }
            case 'e':
            {
                break;
            }
            case 'c':
            {
                int nr;
                std::cout << "Nodul cautat: ";
                std::cin >> nr;
                if(cautare(rad, nr))
                    std::cout << "Nod gasit\n";
                else
                    std::cout << "Nu s-a gasit nod\n";
                break;
            }
            case 'p':
            {
                std::cout << "Parcurgerea de proba: ";
                Parcurgere_inordine(rad);
                break;
            }
            case 'A':
            {
                int nr;
                std::cout << "Numar de ordine: ";
                std::cin >> nr;
                if(rad)
                    Adaug(rad, nr);
                else if(nr)
                {
                    rad = new Arbore;
                    rad->info = nr;
                    rad->st = NULL;
                    rad->dr = NULL;
                }
                break;
            }
            case 'E':
            {
                break;
            }
            case 'C':
            {
                int nr;
                std::cout << "Nodul cautat: ";
                std::cin >> nr;
                if(cautare(rad, nr))
                    std::cout << "Nod gasit\n";
                else
                    std::cout << "Nu s-a gasit nod\n";
                break;
            }
            case 'P':
            {
                std::cout << "Parcurgerea de proba: ";
                Parcurgere_inordine(rad);
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
    return 0;
}
