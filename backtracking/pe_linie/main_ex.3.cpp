#include <iostream>

int st[10], i, n, k;

void init()
{
    st[k] = 0;
}

int succesor()
{
    if(k == 1)
    {
        if(st[k] < 8)
        {
            st[k] += 2;
            return 1;
        }
        else
            return 0;
    }
    else
    {
        if(st[k] < 9)
        {
            st[k]++;
            return 1;
        }
        else
            return 0;
    }
}

int valid()
{
    return 1;
}

int solutie()
{
    return k == n;
}

void tipar()
{
    for(i = 1; i <= k; i++)
        std::cout << st[i];
    std::cout << "\n";
}

void back()
{
    int as;
    k = 1;
    init();
    while(k > 0)
    {
        do{}while ((as = succesor()) && !valid());
        if(as)
            if(solutie())
                tipar();
            else
            {
                k++;
                init();
            }
        else
            k--;
    }
}

int main()
{
    std::cin >> n;
    back();
    return 0;
}