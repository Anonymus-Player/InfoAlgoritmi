#include <iostream>
#include <fstream>

#define Pinf 10000000

float A[50][50], D[50], Min;
int S[50], T[50], n, i, j, r, poz;

void Citire_cost(const char* File_name, float V[50][50], int &p)
{
    int i, j;
    float c;
    std::ifstream f(File_name);
    f >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i == j)
                V[i][j] = 0;
            else
                V[i][j] = Pinf;
    while(f >> i >> j >> c)
        V[i][j] = c;
}

void Drum(int i)
{
    if(T[i])
        Drum(T[i]);
    std::cout << i << " ";
}

int main()
{
    Citire_cost("Graf.txt", A, n);
    std::cout << "r = ";
    std::cin >> r;
    S[r] = 1;
    for(i = 1; i <= n; i++)
    {
        D[i] = A[r][i];
        if(i != r && D[i] < Pinf)
            T[i] = r;
    }
    for(i = 1; i <= n - 1; i++)
    {
        Min = Pinf;
        for(j = 1; j <= n; j++)
            if(S[j] == 0 && D[j] < Min)
            {
                Min = D[j];
                poz = j;
            }
        S[poz] = 1;
        for(j = 1; j <= n; j++)
            if(S[j] == 0 && D[j] > D[poz] + A[poz][j])
            {
                D[j] = D[poz] + A[poz][j];
                T[j] = poz;
            }
    }
    for(i = 1; i <= n; i++)
        if(i != r && T[i])
        {
            std::cout << "Distanta de la " << r << " la " << i << " este: " << D[i] << "\n";
            Drum(i);
            std::cout << "\n";
        }
        else
            std::cout << "Nu exista drum.\n";
    return 0;
}
