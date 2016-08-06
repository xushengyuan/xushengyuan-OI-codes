#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#define MAXN 100000
using namespace std;
int f[MAXN];
int t,m;
struct thing
{
    int c,w;
}a[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j;
    cin>>t>>m;
    for(i=0;i<m;i++)
        cin>>a[i].c>>a[i].w;
    for(i=0;i<m;i++)
        for(j=a[i].c;j<=t;j++)
            f[j]=max(f[j],f[j-a[i].c]+a[i].w);
    cout<<f[t];
    return 0;
}
