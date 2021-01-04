#include <iostream>
#include <fstream>

int max(int x, int y)
{
    if(x > y)
        return x;
    return y;
}

int main()
{
    std::ifstream f("pir.in");
    int a[20][20], v1[20], v2[20], i, j, n, k;
    f >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
            f >> a[i][j];
    k = n;
    if(n % 2 == 0)
        for(i = 1; i <= n; i++)
            v2[i] = a[n][i];
    else
        for(i = 1; i <= n; i++)
            v1[i] = a[n][i];
    while(k >= 1)
    {
        k--;
        if(k % 2 == 1)
            for(i = 1; i <= k; i++)
                v1[i] = a[k][i] + max(v2[i], v2[i + 1]);
    }
}
