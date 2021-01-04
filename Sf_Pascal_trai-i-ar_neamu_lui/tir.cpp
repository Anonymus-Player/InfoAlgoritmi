#include <iostream>
#include <fstream>

#define maxN 50

short int valori[maxN], c[maxN], d[maxN];

short int n, i, j, k;

bool operatii;

std::ifstream f;

void citire()
{
    f.open("tir.in");
    f >> n >> k;
    for(i = 1; i <= n; i++)
        f >> valori[i];
    f.close();
}

void calcul()
{
    c[0] = 1;
    for(j = 1; j <= n; j++)
        for(i = 0; i <= k - valori[j]; i++)
            if(c[i] > 0)
                if(c[i + valori[j]] > c[i] + 1 || c[i + valori[j]] == 0)
                {
                    c[i + valori[j]] = c[i] + 1;;
                    d[i + valori[j]] = i;
                }
}

void reconstituire(int p)
{
    if(p != 0)
    {
        reconstituire(d[p]);
        std::cout << "Folosesc valoare: " << p - d[p] << "\n";
    }
}

int main()
{
    citire();
    calcul();
    if(c[k] == 0)
        std::cout << "Imposibil/n";
    else
    {
        std::cout << "Numarul minim de operatii: " << c[k] - 1 << "\n";
        reconstituire(k);
    }
    return 0;
}
