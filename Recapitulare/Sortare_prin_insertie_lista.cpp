#include <iostream>

struct Lista
{
    int info;
    Lista *urm;
}*s1, *s2, *c, *d;

int main()
{
    int i, n, x;
    std::cin >> n;
    s1 = new Lista;
    s2 = new Lista;
    s1->info = -1000000;
    s2->info = 1000000;
    s1->urm = s2;
    s2->urm = nullptr;
    for(i = 1; i <= n; i++)
    {
        std::cin >> x;
        c = s1;
        while(c->urm->info < x)
            c = c->urm;
        d = new Lista;
        d->info = x;
        d->urm = c->urm;
        c->urm = d; 
    }
    c = s1->urm;
    while(c->urm)
    {
        std::cout << c->info << " ";
        c = c->urm;
    }
    return 0;
}