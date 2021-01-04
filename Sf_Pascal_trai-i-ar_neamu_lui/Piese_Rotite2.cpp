#include <iostream>
#include <fstream>

int a[1001][1], c[1001][1];
std::ifstream f;
int n, i, j, k, L, max, poz, distanta;

int d(int q, int w)
{
	if(q == w)
		return 1;
	else
		return 0;
}

void citire()
{
	f.open("domino.in");
	f >> n;
	for(i = 1; i <= n; i++)
		f >> a[i][0] >> a[i][1];
	f.close();
}

void calcul()
{
	c[1][0] = 1;
	c[1][1] = 1;
	for(i = 2; i <= n; i++)
		for(j = 0; j <= 1; j++)
		{
			max = 1;
			for(L = 1; L <= i - 1; L++)
				for(k = 0; k <= 1; k++)
				{
					distanta = d(a[i][j], a[L][1 - k]);
					if(distanta == 1)
						if(max < c[L][k] + distanta)
							max = c[L][k] + distanta;
				}
            c[i][j] = max;
		}
}

int main()
{
    citire();
    calcul();
    max = 1;
    poz = 1;
    for(i = 2; i <= n; i++)
        for(j = 0; j <= 1; j++)
            if(c[i][j] > max)
            {
                max = c[i][j];
                poz = i;
            }
    std::cout << max << " " << poz;
    return 0;
}

