#include <iostream>

int st[10], i, k, n;

void init()
{
    st[k] = 0;
}

int succesor()
{
    if(st[k] < 2)
    {
        st[k]++;
        return 1;
    }
    else
        return 0;
}

int valid()
{
    int p = 0, t = 0;
    for(i = 1; i <= k; i++)
    {
        if(st[i] == 1)
            p++;
        else
            t++;
    }
    return (p >= t) && (p <= n / 2);
}

int solutie()
{
    int p = 0, t = 0;
    for(i = 1; i <= k; i++)
    {
        if(st[i] == 1)
            p++;
        else
            t++;
    }
    return (k == n) && (p == t);
}

void afisare()
{
    for(i = 1; i <= k; i++)
    {
        if(st[i] == 1)
            std::cout << "(";
        else if(st[i] == 2)
            std::cout << ")";
    }
    std::cout << "\n";
}

void back()
{
    int as;
    k = 1;
    init();
    while(k > 0)
    {
        do{}while((as = succesor()) && !valid());
        if(as)
        {
            if(solutie())
                afisare();
            else
            {
                k++;
                init();
            }
        }
        else
            k--;
    }
}

int main()
{
    std::cin >> n;
    if(n % 2 == 1)
    {
        std::cout << "Nu se poate\n";
    }
    else
        back();
    return 0;
}
