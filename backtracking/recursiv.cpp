#include <iostream>
#include <math.h>

using namespace std;
int t[20], n, i;

void tipar()
{
    for(i=1; i<=n; i++)
        cout<<t[i];
    cout<<endl;
}

void dame(int k)
{
    int j, corect;
    if(k==n+1)
        tipar();
    else
    {
        for(i=t[k]+1; i<=n; i++)
        {
            t[k]=i;
            corect=1;
            for(j=1; j<=k-1; j++)
                if(t[j]==t[k])
                    corect=0;
            if(corect)
                dame(k+1);
        }
    }
    t[k]=0;
}

int main()
{
    cout<<"n=";
    cin>>n;
    dame(1);
}
