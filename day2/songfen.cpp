#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
int a[MAXN],b[MAXN];
int f[MAXN];
int n,p;
int main()
{
    freopen("songfen.in","r",stdin);
    freopen("songfen.out","w",stdout);
    cin >>n>>p;
    for (int i = 1; i <= n; i++)
        cin >>a[i];
    int max=-12345678;
    fill(f,f+MAXN,-123456);
    for (int i = 1; i <= n; i++)
    {
        swap(p,a[i]);
        //DP
        /*for(int z=1;z<=n;z++)
            cout<<a[z]<<' ';
        cout <<endl;*/
        for(int j=1;j<=n;j++)
        {
            if(f[j-1]>0)
                f[j]=f[j-1]+a[j];
            else
                f[j]=a[j];
            if(f[j]>max)
                max=f[j];
        }
        swap(a[i],p);
    }
    cout<<max;
    return 0;
}