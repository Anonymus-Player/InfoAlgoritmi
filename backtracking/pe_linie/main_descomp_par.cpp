#include <iostream>

int st[10], i, n, k;

void init()
{
    st[k] = 0;
}

int succesor()
{
    int s = 0;
    for(i = 1; i <= k - 1; i++)
	    s += st[i];
    if(st[k] < n - s)
    {
	    st[k]++;
	    return 1;
    }
    else
	return 0;
}

int valid()
{
    return 1;
}

int solutie()
{
    int s = 0, ok = 1;
    for(i = 1; i <= k; i++)
        if(st[i] % 2 == 1)
            ok = 0;
    for(i = 1; i <= k; i++)
        s += st[i];
    return (s == n) && ok;
}

void afisare()
{
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
    back();
    return 0;
}