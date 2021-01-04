#include <iostream>

int st[10], i, m, n, k, p = 0;

void init()
{
    st[k] = -2;
}

int succesor()
{
    if(st[k] < 1)
    {
	    st[k]++;
	    return 1;
    }
    else
        return 0;
}

int valid()
{
    int s = 0;
    for(i = 1; i <= k; i++)
        s = s + (st[i] * st[i]);
    return s <= m;
}

int solutie()
{
    int s = 0;
    for(i = 1; i <= k; i++)
        s = s + (st[i] * st[i]);
    return s == m;
}

void afisare()
{
    p++;
    std::cout << "{ ";
    for(i = 1; i <= k; i++)
	    std::cout << st[i] << " ";
    std::cout << "}\n";
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
            if(k == n)
            {
                if(solutie())
                    afisare();
            }
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
    std::cin >> n >> m;
    back();
    return 0;
}
