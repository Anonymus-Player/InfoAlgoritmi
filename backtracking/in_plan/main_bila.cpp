#include <fstream>
#include <iostream>

std::ofstream out("bila.out");
std::ifstream in("masa.in");
int st[100][4], a[20][20], i, j, k, n, m, x, y, x1, y1, t = 0, max = 0;

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
            if(a[x1 - 1][y1] > a[x1][y1])
                x1--;
            else
                g = 0;
            break;
        }
        case 2:
        {
            if(a[x1 - 1][y1 + 1] > a[x1][y1])
            {
                x1--;
                y1++;
            }
            else
                g = 0;
            break;
        }
        case 3:
        {
            if(a[x1][y1 + 1] > a[x1][y1])
                y1++;
            else
                g = 0;
            break;
        }
        case 4:
        {
            if(a[x1 + 1][y1 + 1] > a[x1][y1])
            {
                x1++;
                y1++;
            }
            else
                g = 0;
            break;
        }
        case 5:
        {
            if(a[x1 + 1][y1] > a[x1][y1])
                x1++;
            break;
        }
        case 6:
        {
            if(a[x1 + 1][y1 - 1] > a[x1][y1])
            {
                x1++;
                y1--;
            }
            else
                g = 0;
            break;
        }
        case 7:
        {
            if(a[x1][y1 - 1] > a[x1][y1])
                y1--;
            else
                g = 0;
            break;
        }
        case 8:
        {
            if(a[x1 - 1][y1 - 1] > a[x1][y1])
            {
                x1--;
                y1--;
            }
            else
                g = 0;
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
    return a[st[k][2]][st[k][3]] == max + 1;
}

void tipar()
{
    t++;
    out << "Solutia nr: " << t << "\n" << "este: \n";
    for(i = 1; i < k; i++)
        out << st[i][2] << " " << st[i][3] << "\n";
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
        {
            in >> a[i][j];
            if(max < a[i][j])
                max = a[i][j];
        }
    for(i = 0; i <= m + 1; i++)
        a[0][i] = a[n + 1][i] = max + 1;
    for(i = 0; i <= n + 1; i++)
        a[i][0] = a[i][m + 1] = max + 1;
}

int main()
{
    citire();
    back();
    return 0;
}