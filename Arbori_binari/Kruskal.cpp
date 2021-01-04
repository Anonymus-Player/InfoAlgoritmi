#include<iostream>
#include<fstream>

struct Nod
{
    float cost;
    int nod1;
    int nod2;
} v[20];

int n;

void citire()
{
    std::ifstream f("graf.txt");
    int x, y, j = 1;
    float z;
    n = 0;
    while(f >> x >> y >> z)
    {
        v[j].nod1 = x;
        v[j].nod2 = y;
        v[j].cost = z;
        if(n < x)
            n = x;
        j++;
    }
}

int kruskal()
{
    int l[20], i, j, k, c = 0;
    i = 1;
    for(k = 1; k <= n - 1; k++)
    {
        while(l[v[i].nod1] == l[v[i].nod2] && l[v[i].nod1] != 0)
            i++;
        c += v[i].cost;

        if(l[v[i].nod1] + l[v[i].nod2] == 0)
            l[v[i].nod1] = l[v[i].nod2] = v[i].nod1;

        else if(l[v[i].nod1] * l[v[i].nod2] == 0)
            l[v[i].nod1] = l[v[i].nod2] = l[v[i].nod1] + l[v[i].nod2];

        else
        {
            for(j = 1; j<= n; j++)
                if(l[j] == l[v[i].nod1] && j != v[i].nod1)
                    l[j] = l[v[i].nod2];

            l[v[i].nod1] = l[v[i].nod2];
        }
        i++;
    }

    return c;
}

int main()
{
    citire();
    std::cout << kruskal() << "\n";

    return 0;
}
