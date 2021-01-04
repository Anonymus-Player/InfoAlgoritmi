#include <iostream>

int st[20], a[20], b[20], i, k, n;

void init()
{
    st[k] = 0;
}

int succesor()
{
    if(st[k] < b[k])
    {
        st[k]++;
        return 1;
    }
    else
        return 0;
}

int valid()
{
    int sum = 0;
    for(i = 1; i <=k; i++)
        sum += st[i] * a[i];
    return sum <= n;
}

int solutie()
{
    int sum = 0;
    for(i = 1; i <=k; i++)
        sum += st[i] * a[i];
    return sum == n;
}

void tipar()
{
    i = 1;
    while(st[i] == 0)
    {
        std::cout << a[i] << " * " << st[i] << " + ";
        i++;
    }
    while(st[i] != 0 && st[i + 1] != 0)
    {
        std::cout << a[i] << " * " << st[i] << " + ";
        i++;
    }
    std::cout << a[i] << " * " << st[i] << " = " << n << "\n";
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

void citire()
{
    int p;
    std::cin >> n >> p;
    for(i = 1; i <=p; i++)
    {
        std::cin >> a[i];
        b[i] = (int)(s / a[i]);
    }
}

int main()
{
    citire();
    back();
    return 0;
}
