#include <iostream>

int pos(int a[100], int li, int ls)
{
    int i = li, j = ls, c, j1 = -1, i1 = 0;
    while(i < j)
    {
        if(a[i] > a[j])
        {
            c = a[i];
            a[i] = a[j];
            a[j] = c;
            c = -j1;
            j1 = -i1;
            i1 = c;
        }
        i += i1;
        j += j1;
    }
    return i;
}

int v[100], i, n;

void quick(int li, int ls)
{
    if(li < ls)
    {
        int k = pos(v, li, ls);
        quick(li, k - 1);
        quick(k + 1, ls);
    }
}

int main()
{
    std::cin >> n;
    for(i = 1; i <= n; i++)
        std::cin >> v[i];
    quick(1, n);
    for(i = 1; i <= n; i++)
        std::cout << v[i] << " ";
}