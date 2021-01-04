#include <iostream>

int st[50], i, k, S;

void init()
{
    st[k] = 0;
}

int succesor()
{
    int sum = 0;
    for(i = 1; i < k; i++)
        sum += st[i];
    if(st[k] < S - sum)
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
    int sum = 0;
    for(i = 1; i <= k; i++)
        sum += st[i];
    return sum == S;
}

void tipar()
{
    std::cout << "{ ";
    for(i = 1; i <= k ; i++)
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
    std::cin >> S;
    back();
    return 0;
}