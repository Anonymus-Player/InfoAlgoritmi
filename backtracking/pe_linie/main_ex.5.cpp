#include <iostream>

int st[20], i, n, k, x, y;

void init()
{
    st[k] = 0;
}

int succesor()
{
    if(st[k] < n)
    {
        st[k]++;
        return 1;
    }
    else
        return 0;
}

int valid()
{
    for(i = 1; i < k; i++)
        if(st[i] == st[k])
            return 0;
    return 1;
}

int solutie()
{
    if(k == n)
    {
        for(i = 1; i <= k; i++)
        {
            if(st[i] == y)
                return 1;
            if(st[i] == x)
                return 0;
        }
    }
    return 0;
}

void tipar()
{
    for (i = 1; i <= k; i++)
        std::cout << st[i] << " ";
    std::cout << "\n";
}

void back()
{
    int as;
    k = 1;
    init();
    while (k > 0)
    {
        do{}while((as = succesor()) && !valid());
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
    std::cin >> n >> y >> x;
    back();
    return 0; 
}
