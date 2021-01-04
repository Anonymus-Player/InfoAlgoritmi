#include <fstream>
#include <iostream>
#include <memory.h>

std::ofstream cal("cal.txt");
int st[100][3], a[20][20], n, m, i, j, k, x, y, x1, y1, nr = 0, p = 0;

void init()
{
    st[k][1] = 0;
    st[k][2] = x1;
    st[k][3] = y1;
}

int succesor()
{
    if(st[k][1] < 8)
    {
        st[k][1]++;
        return 1;
    }
    else
    {
        nr--;
        a[st[k][2]][st[k][3]] = 0;
        return 0;
    }
}

int valid()
{
    int g = 1;
    x1 = st[k][2];
    y1 = st[k][3];
    switch(st[k][1])
    {
        case 1:
        {
            if(!a[x1 - 2][y1 + 1])
            {
                x1 -= 2;
                y1++;
            }
            else
                g = 0;
            break;
        }
        case 2:
        {
            if(!a[x1 - 1][y1 + 2])
            {
                x1--;
                y1 += 2;
            }
            else
                g = 0;
            break;
        }
        case 3:
        {
            if(!a[x1 + 1][y1 + 2])
            {
                x1++;
                y1 += 2;
            }
            else
                g = 0;
            break;
        }
        case 4:
        {
            if(!a[x1 + 2][y1 + 1])
            {
                x1 += 2;
                y1++;
            }
            else
                g = 0;
            break;
        }
        case 5:
        {
            if(!a[x1 + 2][y1 - 1])
            {
                x1 += 2;
                y1--;
            }
            else
                g = 0;
            break;
        }
        case 6:
        {
            if(!a[x1 + 1][y1 -2])
            {
                x1++;
                y1 -= 2;
            }
            else
                g = 0;
            break;
        }
        case 7:
        {
            if(!a[x1 - 1][y1 - 2])
            {
                x1--;
                y1 -= 2;
            }
            else
                g = 0;
            break;
        }
        case 8:
        {
            if(!a[x1 - 2][y1 - 1])
            {
                x1 -= 2;
                y1--;
            }
            else
                g = 0;
            break;
        }
        default:
            break;
    }
    if(g)
    {
        nr++;
        a[x1][y1] = nr;
    }
    return g;
}

int solutie()
{
    return nr == n * n;
}


void tipar()
{
    p++;
    cal << "Solutia numaru: " << p << "\n" << "Este:\n{\n";
    for(i = 1; i <= k; i++)
        cal << st[i][2] - 1 << " " << st[i][3] - 1 << "\n";
    cal << "}\n";
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
            {
                tipar();
                nr--;
                a[x1][y1] = 0;
            }
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
    std::cin >> n >> x >> y;
    x1 = x + 1;
    y1 = y + 1;
    memset(a, 0, sizeof(a));
    for(i = 0; i <= n + 3; i++)
    {
        a[0][i] = a[n + 2][i] = a[1][i] = a[n + 3][i] = 1;
        a[i][0] = a[i][n + 2] = a[i][1] = a[i][n + 3] = 1;
    }
    a[x1][y1] = nr = 1;
}

int main()
{
    citire();
    back();
    return 0;
}
