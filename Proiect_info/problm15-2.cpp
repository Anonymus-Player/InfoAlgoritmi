/* Sa se verifice daca un graf orientat este regulat de grad k, unde k este citit de la tastatura.
Graful este dat prin matricea de adiacenta(un graf este regulat daca toate varfurile sale au acealsi grad).

Explicatie:
Se va calcula gradul total al unui varf(extern si intern) si se va verifica daca este egal cu o valoare data.
*/

#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

int k , a[20][20], i, j, sum1[20],n;

void citire()
{
    ifstream f("graf.in");
    f >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n ;j++)
            f >> a[i][j];
}
void suma()
{
    int ok = 1;
    cin >> k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n ;j++)
            sum1[i] += a[i][j] + a[j][i];
    for(i = 1; i <= n; i++)
        if(sum1[i] != k)
            ok = 0;
    if(ok == 1)
        cout << "Graful este regulat de grad " << k << endl;
    else
        cout << "Graful NU este regulat de grad " << k << endl;
 }
int main()
{
    memset(sum1, 0, sizeof(sum1));
    citire();
    suma();
    return 0;
}

/*
Exemple:
3
0 1 0
0 0 1
1 0 0

k = 2
Afisare: Graful este regulat de grad 2
3
0 1 0
0 0 1
1 0 0

k = 5
Afisare: Graful este regulat de grad 5
*/
