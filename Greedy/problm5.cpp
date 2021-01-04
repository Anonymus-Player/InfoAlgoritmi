#include <iostream>

using namespace std;

int i, n, v[20];

int pos(int* v, int li, int ls)
{
    int i = li, j = ls, i1 = 1, j1 = 0, c;
    while(i <= j)
    {
        if(v[i] > v[j])
        {
            c = v[i];
            v[i] = v[j];
            v[j] = c;
            c = -i1;
            i1 = -j1;
            j1 = c;
        }
        i += i1;
        j += j1;
    }
    return i;
}

void quick(int* v, int li, int ls)
{
    if(li < ls)
    {
        int k;
        k = pos(v, li, ls);
        quick(v, li, k - 1);
        quick(v, k + 1, ls);
    }
}

int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    quick(v, 1, n);
    for(i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
