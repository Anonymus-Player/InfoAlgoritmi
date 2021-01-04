#include <iostream>

int v[100], i, n;

int f(int li, int ls)
{
    int lm;
    int x, y;
    if(li == ls)
        return v[li];
    else if(ls - li == 1)
        return v[li] * v[ls];
    else
    {
        lm = (li + ls) / 2;
        x = f(li, lm);
        y = f(lm + 1, ls);
        return x * y;
    }
}

int main()
{
    std::cin >> n;
    for(i = 1; i <= n; i++)
        std::cin >> v[i];
    std::cout << f(1, n);
}
