#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n;
int f[20000];
struct thing
{
    int p;
    int v;
}th[20000];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    cin>>m>>n;
    for(i=1;i<=n;i++)
    {
        cin>>th[i].p;
        th[i].v=th[i].p;
    }
    f[0]=0;
    for(i=1;i<=n;i++)
        for(j=m;j>=th[i].p;j--)
            f[j]=max(f[j],f[j-th[i].p]+th[i].v);
    cout<<m-f[m];
    return 0;
}
