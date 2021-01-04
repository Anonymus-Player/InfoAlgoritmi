#include <iostream>
#include <fstream>

struct Arbore
{
    int info;
    Arbore *st, *dr;
}*rad;

int v[20], a[20], n;
std::ifstream f("parcurgere.txt");

int divide(int li, int ls, int nr)
{
    if(li == ls)
    {
        if(v[li] == nr)
            return li;
        else
            return 0;
    }
    else if(ls - li == 1)
    {
        if(v[li] == nr)
            return li;
        else if (v[ls] == nr)
            return ls;
        else
            return 0;
    }
    else
    {
        int x, y, lm;
        lm = (li + ls) / 2;
        x = divide(li, lm, nr);
        y = divide(lm + 1, ls, nr);
        if(x)
            return x;
        else if(y)
            return y;
    }
}

Arbore* Cautare(Arbore *Nod, int nr)
{
    if(Nod)
    {
        if(Nod->info == nr)
            return Nod;
        Cautare(Nod->st, nr);
        Cautare(Nod->dr, nr);
    }
    else
        return NULL;
}

Arbore* Adaugare(int nr)
{
    Arbore *Nod;
    Nod = new Arbore;
    Nod->info = nr;
    Nod->st = Nod->dr = NULL;
    return Nod;
}

void Citire()
{
    int i;
    f >> n;
    for(i = 1; i <= n; i++)
        f >> v[i];
    for(i = 1; i <= n; i++)
        f >> a[i];
}

void Reconstruire()
{
    int i, j, pos;
    rad = Adaugare(v[n / 2]);
    if(a[1] == v[n / 2])
    {
        j = n / 2;
        for(i = 2; i <= n; i++)
        {
            pos = divide(1, n, a[i]);
            if(pos > j)
                Cautare(rad, a[i - 1])->dr = Adaugare(a[i]);
            else
                Cautare(rad, a[i - 1])->st = Adaugare(a[i]);
            j = pos;
        }
    }
    else if(a[n] == v[n / 2])
    {
        j = n / 2;
        for(i = n - 1; i >= 1; i--)
        {
            pos = divide(1, n, a[i]);
            if(pos > j)
                Cautare(rad, a[i + 1])->dr = Adaugare(a[i]);
            else
                Cautare(rad, a[i + 1])->st = Adaugare(a[i]);
            j = pos;
        }
    }
}

void sdr(Arbore *Nod)
{
    if(Nod)
    {
        sdr(Nod->st);
        sdr(Nod->dr);
        std::cout << Nod->info << " ";
    }
}

void rsd(Arbore *Nod)
{
    if(Nod)
    {
        std::cout << Nod->info << " ";
        rsd(Nod->st);
        rsd(Nod->dr);
    }
}

void Parcurgere(Arbore *Nod)
{
    if(a[1] == v[n / 2])
        sdr(Nod);
    else if(a[n] == v[n / 2])
        rsd(Nod);
    std::cout << "\n";
}

int main()
{
    Citire();
    Reconstruire();
    Parcurgere(rad);
    return 0;
}
