#include <iostream>
#include <fstream>
#include <memory.h>

int a[100][100], b[100][100], cost[2][100], cerere[100];
std::ifstream f("depozit.in");
int n, x1, x2, h1, h2, i, j, k;

void citire()
{
    f >> n >> x1 >> x2;
    for(i = 1; i <= n; i++)
        f >> cerere[i];
    for(i = 1; i <= 2; i++)
        for(j = 1; j <= n; j++)
            f >> cost[i][j];
}

int min(int a, int b)
{
    if(a > b)
        return b;
    return a;
}

void calcul()
{
    for(i = 0; i <= x1; i++)
        for(j = 0; j <= x2; j++)
            if(i + j == cerere[1])
                a[i][j] = cost[1][1] * i + cost[2][1] * j;
    for(k = 2; k <= n; k++)
    {
        for(i = 0; i <= x1; i++)
            for(j = 0; j <= x2; j++)
            {
                b[i][j] = 65535;
                for(h1 = 0; h1 <= i; h1++)
                    for(h2 = 0; h2 <= j; h2++)
                        if(h1 + h2 == cerere[k])
                            b[i][j] = min(b[i][j], cost[1][k] * h1 + cost[2][k] * h2 + a[i - h1][j - h2]);
            }
        memcpy(a, b, sizeof(b));
    }
}

int main()
{
    citire();
    calcul();
    std::cout << a[x1][x2];
    return 0;
}
