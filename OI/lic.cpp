#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n=0,mx_n;
int a[1000],f[1000][1000];
int DP()
{
    int i,mx=0,j,l,k;
    for(i=n-2;i>=0;i--)
    {
        l=0;
        k=0;
        for(j=i+1;j<n;j++)
        {
            if(f[i][1]<f[j][1]&&f[j][2]>1)
            {
                l=f[j][2];
                k=j;
            }
        }
        if(l>0)
        {
            f[i][2]=l+1;
            f[i][3]=k;
        }
    }
    for(j=1;j<=n;j++)
        if(f[j][2]>f[k][2])
            k=j;
    return f[k][2];
}
int main()
{
    freopen("lic.in","r",stdin);
    //freopen("lic.out","w",stdout);
    memset(a,0,sizeof(int));
    memset(f,0,sizeof(int));
    int i; 
    while(~scanf("%d",&a[n]))
        n++;
    //cout<<n<<endl;
    for(i=0;i<n;i++)
        f[i][2]=1,f[i][3]=0;
    int max_long;
    max_long=DP();
    cout<<"max="<<max_long<<endl;
    for(i=mx_n-max_long+1;i<=mx_n;i++)
        cout<<a[i]<<' ';
    return 0;
}
