#include <iostream>

int v[100], i, n;

int pos(int li, int ls, int p)
{
    if(li == ls)
        if(v[p] >= v[li])
            return ls + 1;
        else
            return li;
    else if(ls - li == 1)
        if(v[p] >= v[ls])
            return ls + 1;
        else if(v[p] >= v[li])
            return ls;
        else
            return li;
    else
    {
        int k = (li + ls) / 2;
        if(v[p] <= v[k])
            return pos(li, k, p);
        else
            return pos(k + 1, ls, p);
    }
}

void permc(int p1, int p2)
{
    int c;
    c = v[p2];
    for(i = p2; i > p1; i--)
        v[i] = v[i - 1];
    v[p1] = c;
}

void sort(int ls)
{
    for(int j = 2; j <= ls; j++)
    {
        int q = pos(1, j - 1, j);
        if(q != j)
            permc(q, j);
    }
}

int main()
{
    std::cin >> n;
    for(i = 1; i <= n; i++)
        std::cin >> v[i];
    sort(n);
    for(i = 1; i <= n; i++)
        std::cout << v[i] << " ";
    return 0;
}