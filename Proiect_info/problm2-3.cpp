/**
Se da un graf orientat in care arcele au asociate costuri(nr naturale nenule).
Sa se determine cate arce de forma (x,y) din graf au costul egal cu costul drumului de cost minim de la x la y.
Explicatie: Se poate folosi algoritmul lui Roy-Warshall pentru determinarea drumului de cost minim de la x la y.
Aceasta valoare va fi comparata, pe rand, cu fiecare drum initial de la x la y naturale nenule.
*/

#include <iostream>
#include <fstream>
#include <memory.h>

#define Pinf 10000000

using namespace std;

float A[50][50], B[50][50];
int n, k, i, j, nr = 0;

void Citire_cost(const char* File_name, float V[50][50], int &p)
{
    int i, j;
    float c;
    ifstream f(File_name);
    f >> p;
    for(i = 1; i <= p; i++)
        for(j = 1; j <= p; j++)
            if(i == j)
                V[i][j] = 0;
            else
                V[i][j] = Pinf;
    while(f >> i >> j >> c)
        V[i][j] = c;
}

int main()
{
    Citire_cost("graf.txt", A, n);
    Citire_cost("graf.txt", B, n);

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(A[i][j] > A[i][k] + A[k][j])
                    A[i][j] = A[i][k] + A[k][j];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(B[i][j] != Pinf && i != j)
                if(B[i][j] == A[i][j])
                    nr++;

    cout << "Numarul de arce cu lungimea egala cu lungimea drumului minim sunt: " << nr << "\n";
    return 0;
}
/**
Exemplu:
8
1 8 3
2 1 5
2 3 3
2 6 6
3 4 3
4 2 3
4 5 8
5 6 3
6 1 6
6 7 7
8 7 10
Afisare:
Numarul de arce cu lungimea egala cu lungimea drumului minim sunt: 11
*/
