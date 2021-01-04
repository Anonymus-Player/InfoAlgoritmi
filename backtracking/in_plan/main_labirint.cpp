#include <iostream>
#include <fstream>

int st[100][4], a[20][20], n, m, i, j, k, x, y, x1, y1, p = 0;
std::ifstream in("labirint.in");
std::ofstream out("labirint.out");

void init()
{
    st[k][1] = 0;
    st[k][2] = x1;
    st[k][3] = y1;
}

int succesor()
{
    if(st[k][1] < 4)
    {
        st[k][1]++;
        return 1;
    }
    else
        return 0;
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
            if(a[x1][y1] <= 8)
                g = 0;
            else
                x1--;
            break;
        }
        case 2:
        {
            if(a[x1][y1] <= 4 || a[x1][y1] == 8 || a[x1][y1] == 9 || a[x1][y1] == 10 || a[x1][y1] == 11)
                g = 0;
            else
                y1++;
            break;
        }
        case 3:
        {
            if(a[x1][y1] == 1 || a[x1][y1] == 4 || a[x1][y1] == 5 || a[x1][y1] == 8 || a[x1][y1] == 9 || a[x1][y1] == 12 || a[x1][y1] == 13)
                g = 0;
            else
                x1++;
            break;
        }
        case 4:
        {
            if(a[x1][y1] % 2 == 0)
                g = 0;
            else
                y1--;
            break;
        }
        default:
            break;
    }
    for(i = 1; i < k; i++)
        if(st[k][2] == st[i][2] && st[k][3] == st[i][3])
            g = 0;
    return g;
}

int solutie()
{
    return a[st[k][2]][st[k][3]] == -1;
}

void tipar()
{
    p++;
    out << "Solutia nr: " << p << "\n" << "este: \n";
    for(i = 1; i < k; i++)
        switch(st[i][1])
        {
            case 1:
            {
                out << "N ";
                break;
            }
            case 2:
            {
                out << "E ";
                break;
            }
            case 3:
            {
                out << "S ";
                break;
            }
            case 4:
            {
                out << "V ";
                break;
            }
            default:
                break;
        }
    out << "\n";
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
                k--;
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
    std::cin >> x >> y;
    x1 = x;
    y1 = y;
    in >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            in >> a[i][j];
    for(i = 0; i <= m + 1; i++)
        a[0][i] = a[n + 1][i] = -1;
    for(i = 0; i <= n + 1; i++)
        a[i][0] = a[i][m + 1] = -1;
}

int main()
{
    citire();
    back();
    return 0;
}
