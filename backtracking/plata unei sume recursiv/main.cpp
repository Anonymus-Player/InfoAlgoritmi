#include <iostream>

using namespace std;
int sol[10],a[10],b[10],n,i,s, p = 0;

void tipar(int k)
{
    cout<<"solutia " << ++p << ":" <<endl;
    for(i=1;i<=k;i++)
        if(sol[i])
        cout<< sol[i] <<" bancnote de "<<a[i]<<endl;
}

void plata(int k, int s0)
{
    while(sol[k]<b[k] && s0+a[k]<=s)
    {
        sol[k]=sol[k]+1;
        if(sol[k]>0)
            s0+=a[k];
        if(s0==s)
            tipar(k);
        else
            if(k<n)
            plata(k+1,s0);
    }
    sol[k]=-1;
}

int main()
{
   cout<<"cate tipuri de bancnote avem?";
   cin>>n;
   cout<<"suma= ";
   cin>>s;
   for(i=1;i<=n;i++)
   {
       cout<<"valoarea monedei de tipul "<<i<<' ';
       cin>>a[i];
       b[i]=s/a[i];
       sol[i]=-1;
   }
   plata(1,0);
}
