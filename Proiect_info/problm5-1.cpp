/**
Se da un graf orientat conex cu n varfuri si nr par de arce.
Sa se determine un graf partial al celui dat care sa fie tare conex si obtinut prin eliminarea a
jumatate din nr de arce.
In cazul in care nu exista se va afisa un mesaj corespunzator.

Explicatie:
Folosim algoritmul sumei de cifre(backtracking) pentru a obtine combinatiile posibile astfel
incat numarul arcelor eliminate sa fie egal cu jumatate din numarul total de arce cu condintia
ca digraful rezultat sa fie tare conex
*/

#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

struct arc
{
    int plec, vin;
}v[50];

int i, n, m, st[50], k, p = 0;

void citire()
{
    int c;
    cout << "Vreti sa cititi din fisier? [1/0] ";
    cin >> c;
    if(c == 1)
    {
        char s[20];
        cin >> s;
        ifstream f(s);
        f >> n >> m;
        for(i = 1; i <= m; i++)
            f >> v[i].plec >> v[i].vin;
    }
    else
    {
        cin >> n >> m;
        for(i = 1; i <= m; i++)
            cin >> v[i].plec >> v[i].vin;
    }
}

void init()
{
    st[k] = -1;
}

int succesor()
{
    if(st[k] < 1)
    {
	    st[k]++;
	    return 1;
    }
    else
        return 0;
}

int valid()
{
    int s = 0;
    for(i = 1; i <= k; i++)
        s += st[i];
    return s <= m / 2;
}

void afisare()
{
    cout << "A " << ++p << " este:\n";
    for(i = 1; i <= k; i++)
        if(st[i] == 0)
            cout << "(" << v[i].plec << ", " << v[i].vin << ")\n";
}

void parc(int x, int a[50][50], int viz[50])
{
    int st1[50], t = 1;
    st1[1] = x;
    viz[x] = 1;
    while(t > 0)
    {
        int j = 1;
        while((j <= n && a[st1[t]][j] == 0) || (a[st1[t]][j] == 1 && viz[j] == 1))
            j++;
        if(j > n)
            t--;
        else
        {
            st1[++t] = j;
            viz[j] = 1;
        }
    }
}

int conex()
{
    int a[50][50], viz1[50], viz2[50];
    memset(a, 0, sizeof(a));

    for(i = 1; i <= m; i++)
        a[v[i].plec][v[i].vin] = 1;

    memset(viz1, 0, sizeof(viz1));
    parc(1, a, viz1);
    for(int i = 2; i <= n; i++)
    {
        memset(viz2, 0, sizeof(viz2));
        parc(i, a, viz2);
        for(int j = 1; j <= n; j++)
            if(viz1[j] != viz2[j])
                return 0;
    }

    return 1;
}

int conex2()
{
    int a[50][50], viz1[50], viz2[50];
    memset(a, 0, sizeof(a));

    for(i = 1; i <= m; i++)
        if(st[i] == 1)
            a[v[i].plec][v[i].vin] = 1;

    memset(viz1, 0, sizeof(viz1));
    parc(1, a, viz1);
    for(int i = 2; i <= n; i++)
    {
        memset(viz2, 0, sizeof(viz2));
        parc(i, a, viz2);
        for(int j = 1; j <= n; j++)
            if(viz1[j] != viz2[j])
                return 0;
    }

    return 1;
}

int solutie()
{
    int s = 0;

    for(i = 1; i <= k; i++)
        s += st[i];
    return s == m / 2;
}

void backtrack()
{
    int as;
    k = 1;
    init();
    while(k > 0)
    {
	    do{}while((as = succesor()) && !valid());
        if(as)
        {
            if(k == m)
            {
                if(solutie())
                    if(conex2())
                        afisare();
            }
            else
            {
                k++;
                init();
            }
        }
        else
            k--;
    }
}

int main()
{
    citire();
    if(conex())
    {
        backtrack();
        if(p == 0)
            cout << "Nu este posibil\n";
    }
    else
        cout << "Nu este posibil\n";
    return 0;
}
/**
Exemplu:
5 10
1 2
1 3
2 3
2 4
2 5
3 4
4 1
4 5
5 3
5 1
Afisare:
A 1 este:
(1, 3)
(2, 3)
(2, 4)
(4, 5)
(5, 1)
A 2 este:
(1, 3)
(2, 4)
(2, 5)
(4, 1)
(5, 3)
*/
