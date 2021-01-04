/**
Se considera un graf orientat cu n noduri, dat prin matricea de adiacenta.
Sa se verifice daca graful este hamiltonian.

Explicatie:
Un graf orientat este Hammiltonian daca exista circuit Hammiltonian.
Pentru a verifica acest lucru vom parcurge digraful(in adancime) si vom verifica daca toate nodurile sunt vizitate
si daca exista circuit.
*/
#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

ifstream f("graf.txt");
int a[20][10], i, n, j, m, viz[20], st[20], k;

void citire()
{
    int x, y;
    memset(a, 0, sizeof(a));
    memset(viz, 0, sizeof(viz));
    f >> n;
    while(f >> x >> y)
        a[x][y] = 1;

}

void parcurgere(int x)
{
    k = 1;
    st[1] = x;
    viz[x] = 1;
    while(k > 0)
    {
        j=1;
        while(j <= n && a[st[k]][j] == 0 || a[st[k]][j] == 1 && viz[j] == 1)
            j++;
        if(j > n)
            k--;
        else
        {
            k++;
            st[k] = j;
            m = j;
            viz[j] = 1;
        }
    }
}

int main()
{
    int ok = 1;
    citire();
    parcurgere(1);
    if(a[m][1] != 1)
        ok = 0;
    for(i = 1; i <= n; i++)
        if(viz[i] == 0)
            ok = 0;
    if(ok == 1)
        cout << "Este Hammiltonian" << endl;
    else
        cout << "Nu este Hamiltonian" << endl;
    return 0;
}
/**
Exemplu:
5
1 2
2 5
3 4
4 1
5 3
Afisare:
Este Hammiltonian.

5
1 2
2 5
3 4
5 3
Afisare:
Nu este Hammiltonian.
*/
