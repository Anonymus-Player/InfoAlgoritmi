#include <iostream>
#include <cmath>

int st[10], i ,n ,k;

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
        if(st[i] == st[k] || fabs(st[i] - st[i + 1]) == 1)
            return 0;
    return 1;
}

int solutie()
{
    return k == n;
}

void tipar()
{
    for(i = 1; i <= k; i++)
        std::cout << st[i] << " ";
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
