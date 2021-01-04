#include <iostream>
#include <fstream>

using namespace std;

int n, v[20];

void citire(int* v, int& n)
{
    int p;
    cout << "Doriti sa cititi de la tastatura sau de la fisire? [1 = Da/0 = Nu] ";
    cin >> p;
    if(p == 1)
    {
        char s[20];
        cin >> s;
        ifstream f(s);
        f >> n;
        for(int i = 1; i <= n; i++)
            f >> v[i];
    }
    else
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> v[i];
    }
}

void subsecventa(int* v, int n)
{
    int s;
    for(int i = 1; i <= n; i++)
    {
        s = v[i];
        for(int j = i + 1; j < n; j++)
        {
            s += v[j];
            if(s % n == 0)
            {
                for(int k = i; k <= j; k++)
                    cout << v[k] << " ";
                cout << "\n";
                return;
            }
        }
    }
}

int main()
{
    citire(v, n);
    subsecventa(v, n);
    return 0;
}
