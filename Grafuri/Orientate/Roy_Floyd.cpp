#include <iostream>
#include <fstream>

std::ifstream f("date.in");

int t[20][20], c[20][20], n;
//desc: Initializare matrice costuri //in: matricea costurilor si numarul de noduri
//out: matricea c modificata corespunzator
void InitializareMatriceCosturi(int c[20][20], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j)
                c[i][j] = 0;
            else
                c[i][j] = 1000;//infinit
}
//desc: initializare matrice traseu cu 0
//in: matricea traseu, numarul de noduri //out: matricea traseu, modificata corespunzator
void InitializareMatriceTraseu(int t[20][20], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            t[i][j] = 0;
}
//desc: Citirea datelor de intrare -> construirea matricei costurilor
//in: - //out: matricea costurilor, matricea traseu initiale, nr de noduri.
void CitireConstruire(int c[20][20], int t[20][20], int &n)
{
    f >> n;
    InitializareMatriceCosturi(c, n);
    InitializareMatriceTraseu(t, n);
    int x, y, cost;
    while(f >> x >> y >> cost)
        c[x][y] = cost;
}
//desc: Det. Matricei drumurilor de cost minim si numerotarea nodurilor de pe traseu
//in: mat cost. c, mat traseu, nr noduri.
//out: matricea drumurilor minim (matricea c modificata), dupa alg lui Roy Floyd, matricea traseu.
void Roy_Floyd(int c[20][20], int t[20][20], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(i != j && j != k && i != k)
                    if(c[i][j] > c[i][k] + c[k][j])
                    {
                        c[i][j] = c[i][k] + c[k][j];
                        t[i][j] = k;
                    }
}
//desc: afisarea nodurilor intermediare de pe traseul drumului cu cost minim dintre nodul x si nodul y.
//in: matricea traseu t, nr noduri. //out: -
void Traseu(int x, int y)
{
    if(t[x][y] != 0)
    {
        int k = t[x][y];
        Traseu(x, k);
        std::cout << k << " ";
        Traseu(k, y);
    }
}
//desc: Afisarea drumurilor de lungime minima si traseu
//in: matricea traseu, matricea drumului, nr de noduri. //out: -
void AfisareDrumuriMinime(int c[20][20], int t[20][20], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j)
                if(c[i][j] < 1000) //infinit
                {
                    std::cout << "Costul minim al drumului de la nodul " << i << " la nodul " << j << " este: " << c[i][j] << "\n";
                    std::cout << "Traseul de cost minim de la nodul " << i << " la nodul " << j << " este: ";
                    std::cout << i << " ";
                    Traseu(i, j);
                    std::cout << j << "\n";
                    std::cout << "\n";
                }
}

int main()
{
    CitireConstruire(c, t, n);
    Roy_Floyd(c, t, n);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            std::cout << c[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    AfisareDrumuriMinime(c, t, n);
    return 0;
}

