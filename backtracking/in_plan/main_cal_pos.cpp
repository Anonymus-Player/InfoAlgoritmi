#include <iostream>
#include <fstream>
#include <memory.h>

std::ifstream out("Cal_modif.out");
int st[100][4], a[20][20], x0, y0, x1, y1, i, j, k, n, nr = 0, p = 0;

void init()
{
    st[k][1] = 0;
    st[k][2] = x0;
    st[k][3] = y0;
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
    x0 = st[k][2];
    y0 = st[k][3];
    switch(st[k][1])
    {
        case 1:
        {
            if(!a[x0 - 2][y0 + 1])
            {
                x0 -= 2;
                y0++;
            }
            else
                g = 0;
            break;
        }
        case 2:
        {
            if(!a[x0 - 1][y0 + 2])
            {
                x0--;
                yo += 2;
            }
            else
                g = 0;
            break;
        }case 3:
        {
            if(!a[x0 + 1][y0 + 2])
            {
                x0++;
                y0 += 2;
            }
            else
                g = 0;
            break;
        }
        case 4:
        {
            if(!a[x0 + 2][y0 + 1])
            {
                x0 += 2;
                y0++;
            }
            else
                g = 0;
            break;
        }
        case 5:
        {
            if(!a[x0 + 2][y0 - 1])
            {
                x0 += 2;
                y0--;
            }
            else
                g = 0;
            break;
        }
        case 6:
        {
            if(!a[x0 + 1][y0 - 2])
            {
                x0++;
                y0 -= 2;
            }
            else
                g = 0;
            break;
        }
        case 7:
        {
            if(!a[x0 - 1][y0 - 2])
            {
                x0--;
                y0 -= 2;
            }
            else
                g = 0;
            break;
        }
        case 8:
        {
            if(!a[x0 - 2][y0 - 1])
            {
                x0 -= 2;
                y0--;
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
        a[x0][y0] = nr;
    }
}

int solutie()
{
    return (st[k][2] == x1 && st[k][3] == y1);
}

void tipar()
{
    p++;
    out << "Solutia numaru: " << p << "\nEste:\n{";
    for(i = 1; i <= k; i++)
        out << st[i][2] - 1 << " " << st[i][3] << "\n";
    out << "}\n";
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
                a[x0][y0] = 0;
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
    std::cout >> "Dimensiunea tablei = ";
    std::cin >> n;
    std::cout << "Originea jucatorului = ";
    std::cin >> x0 >> y0;
    x0++;
    yo++;
    std::cout << "Destinatia = ";
    std::cin >> x1 >> y1;
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
}
