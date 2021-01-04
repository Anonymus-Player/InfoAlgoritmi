/**
Se considera un graf orientat cu n noduri si m arce, dat prin lista arcelor.
Sa se verifice daca graful este eulerian.

Explicatie: Vom calcula suma gradelor interne si suma gradelor externe.
Daca diferenta lor este egala cu 0, inseamna ca gradele sunt egale, iar suma lor este para.
Aceasta este conditia necesara si suficienta pentru a afla daca un graf este eulerian.
*/
#include <fstream>
#include <iostream>
#include <memory.h>


using namespace std;

ifstream f("data.in");

int a[20][20], i, n, j,ok=1, S[20];

void citire()
{
    int x, y;
    f >> n;
    memset(a, 0, sizeof(a));
    while(f >> x >> y)
        a[x][y] = 1;
}

void calcgrade()
{
    int s1,s2;

    for(i=1;i<=n;i++)
    {
        s1=s2=0;
        for( j=1;j<=n;j++)
            {
                s1+=a[i][j];
                s2+=a[j][i];
            }
        if(s1==0 && s2==0 and ok==1)
        {
            cout<<"Nu e Eulerian";
            ok=0;
        }
        S[i]=s1-s2;

    }

    if(ok==1)
    {
        for (i=1;i<=n;i++)
            if (S[i]!=0)
            {
                cout<<"Nu e Eulerian";
                ok=0;
                break;
            }
    }

    if(ok==1)
        cout << "Este Eulerian" << endl;

}


int main()
{
    citire();
    calcgrade();
    return 0;
}
/**
6
1 2
1 3
2 3
2 4
3 2
3 4
4 1
4 5
5 6
6 1

Afisare: Este Eulerian.

5
1 2
1 5
2 1
3 2
4 3
4 5

Afisare: Nu este Eulerian.

Caz particular(exista nod izolat):
5
1 2
1 3
2 1
3 4
4 1
2 3

Afisare: Nu este Eulerian.
*/
