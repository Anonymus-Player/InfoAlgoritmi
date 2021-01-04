#include <iostream>

using namespace std;
int s[20], n;

void tipar(int k)
{
    for(int i=1;i<=n;i++)
        cout<<s[i];
    cout<<endl;
}

void part(int k, int v)
{
    int i;
    s[k]=v;
    tipar(k);
    for(i=1;i<=s[k]-1;i++)
    {
        s[k]=s[k]-i;
        part(k+1,i);
        s[k]=s[k]+i;
    }
}

int main()
{
    cout<<"n=";
    cin>>n;
    part(1,n);
}
