#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,f[30001];
struct thing
{
    int p;
    int v;
}th[27];
int main()
{
    freopen("in.txt","r",stdin);
    memset(f,0,1000*sizeof(int));
    int i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
        cin>>th[i].p>>th[i].v;
    f[0]=0;
    for(i=1;i<=m;i++)
        for(j=n;j>=th[i].p;j--)
            f[j] = max ( f[j] , f[j-th[i].p]+th[i].p*th[i].v );
    cout<<f[n];
    return 0;
}
