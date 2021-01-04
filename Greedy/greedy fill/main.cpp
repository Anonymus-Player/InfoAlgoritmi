#include <iostream>

using namespace std;
int a[10][10], i, j, m, n, x, y;

void scriu(int x, int y, int a[10][10])
{
    if(!a[x][y])
    {
        a[x][y]=1;
        scriu(x+1,y,a);
        scriu(x,y+1,a);
        scriu(x-1,y,a);
        scriu(x,y-1,a);
    }
}

int main()
{
    cout<<"M=";
    cin>>m;
    cout<<"N=";
    cin>>n;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            cout<<"a["<<i<<','<<j<<"]=";
            cin>>a[i][j];
        }
    for(i=1; i<=n; i++)
    {
        a[0][i]=1;
        a[m+1][i]=1;
    }
    for(i=1; i<=m; i++)
    {
        a[i][0]=1;
        a[i][n+1]=1;
    }
    cout<<"X=";
    cin>>x;
    cout<<"Y=";
    cin>>y;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j];
        cout<<endl;
    }

    scriu(x,y,a);
    cout<<endl<<endl;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}
