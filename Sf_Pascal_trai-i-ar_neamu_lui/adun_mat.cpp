#include <iostream>
#include <fstream>

#define maxint uint(-1) / 2

struct ref
{
    int l, c;
    ref *as, *ad;
};

int i, n;
int dim[11], a[10][10];

ref *c;

void costopt(int n, int dim[11], int a[10][10])
{
    int k, i, j, l, m;
    for(i = 1; i <= n; i++)
        a[i][i] = 0;
    for(k = 1; k <= n - 1; k++)
        for(i = 1; i <= n - k; i++)
        {
            j = i + k;
            a[i][j] = maxint;
            for(l = i; l <= j - 1; l++)
            {
                m = a[i][l] + a[l + 1][j] + dim[i] * dim[l + 1] * dim[j + 1];
                if(a[i][j] > m)
                {
                    a[i][j] = m;
                    a[j][i] = l;
                }
            }
        }
    std::cout << "Cost optim: " << a[1][n - 1] << "\n";
}

void sdr(ref *c)
{
    if(c != NULL)
    {
        sdr(c->as);
        sdr(c->ad);
        if(c->l != c->c)
            std::cout << c->l << " " << c->c << "\n";
    }
}

ref* crearb(int a[10][10], int i, int j)
{
    ref *d = new ref;
    d->l = i;
    d->c = j;
    if(i != j)
    {
        d->as = crearb(a, i, a[j][i]);
        d->ad = crearb(a, a[j][i] + 1, j);
    }
    else
    {
        d->as = NULL;
        d->ad = NULL;
    }
    return d;
}

int main()
{
    std::ifstream f("mat.in");
    f >> n;
    for(i = 1; i <= n; i++)
        f >> dim[i];
    costopt(n, dim, a);
    c = crearb(a, 1, n);
    sdr(c);
    return 0;
}
