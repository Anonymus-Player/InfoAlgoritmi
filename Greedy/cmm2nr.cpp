#include <iostream>

using namespace std;

int i, n, Max1, Max2, Min1, Min2, v[20];

void maxime(int* v, int n, int& Max1, int& Max2)
{
    Max1 = Max2 = 0;
    for(i = 1; i <= n; i++)
        if(v[i] > Max1)
        {
            Max2 = Max1;
            Max1 = v[i];
        }
        else if(v[i] > Max2)
            Max2 = v[i];
}

void minime(int* v, int n, int& Min1, int& Min2)
{
    Min1 = Min2 = 10000000;
    for(i = 1; i <= n; i++)
        if(v[i] < Min1)
        {
            Min2 = Min1;
            Min1 = v[i];
        }
        else if(v[i] < Min2)
            Min2 = v[i];
}

int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    maxime(v, n, Max1, Max2);
    cout << "Maximele  sunt: " << Max1 << ", " << Max2 << endl;
    minime(v, n, Min1, Min2);
    cout << "Minimele sunt: " << Min1 << ", " << Min2 << endl;
}
