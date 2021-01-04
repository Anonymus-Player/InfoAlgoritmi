#include <fstream>
#include <iostream>
#include <memory.h>

std::ofstream f("misionari.txt");
int st[5000][6], n, k, i, c1, c2, m1, m2, c, m, x = 0;

void init()
{
    st[k][1] = 0;
    st[k][2] = c1;
    st[k][3] = m1;
    st[k][4] = c2;
    st[k][5] = m2;
}

int succesor()
{
    if(st[k][1] < 5)
    {
        st[k][1]++;
        return 1;
    }
    else
        return 0;
}

int valid()
{
    c1 = st[k][2];
    m1 = st[k][3];
    c2 = st[k][4];
    m2 = st[k][5];
    if(k % 2 == 1)
    {
        switch(st[k][1])
        {
            case 1:
            {
                c1 -= 2;
                c2 += 2;
                break;
            }
            case 2:
            {
                m1 -= 2;
                m2 += 2;
                break;
            }
            case 3:
            {
                c1--;
                c2++;
                m1--;
                m2++;
                break;
            }
            case 4:
            {
                c1--;
                c2++;
                break;
            }
            case 5:
            {
                m1--;
                m2++;
                break;
            }
            default:
                break;
        }
    }
    else
    {
        switch(st[k][1])
        {
            case 1:
            {
                c1 += 2;
                c2 -= 2;
                break;
            }
            case 2:
            {
                m1 += 2;
                m2 -= 2;
                break;
            }
            case 3:
            {
                c1++;
                c2--;
                m1++;
                m2--;
                break;
            }
            case 4:
            {
                c1++;
                c2--;
                break;
            }
            case 5:
            {
                m1++;
                m2--;
                break;
            }
            default:
                break;
        }
    }
    if(c1 < 0 || c2 < 0 || m1 < 0 || m2 < 0)
        return 0;
    if((m1 > 0 && c1 > m1) || (m2 > 0 && c2 > m2))
        return 0;
    if(k > 1 && st[k][1] == st[k - 1][1])
        return 0;
    for(i = 1; i < k; i++)
        if(((k + i) % 2 == 0) && (st[k][2] == st [i][2] && st[k][3] == st[i][3]))
            return 0;
    return 1;
}

int solutie()
{
    return (c1 == 0 && m1 == 0);
}

void tipar()
{
    x++;
    f << "Solutia numarul: " << x << "\n" << "Este:\n";
    for(i = 1; i <= k; i++)
        f << st[i][2] << " " << st[i][3] << " " << st[i][4] << " " << st[i][5] << "\n";
    f << "0 0 " << c << " " << m << "\n";
}

void back()
{
    int as;
    k = 1;
    init();
    while(k > 0)
    {
        do{}while((as = succesor()) && !valid());
        if (as)
        {
            if(solutie())
                tipar();
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
    std::cout << "Canibali = ";
    std::cin >> c;
    std::cout << "Misionari = ";
    std::cin >> m;
    c1 = c;
    m1 = m;
    c2 = m2 = 0;
    if(c > m)
        std::cout << "NU EXISTA SOLUTIE";
    else
    {
        back();
        if(x == 0)
            std::cout << "IMPOSIBIL";
    }
    return 0;
}
