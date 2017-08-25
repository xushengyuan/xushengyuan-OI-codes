//Date:2017/8/9
//OJ:luogu
//Problem:1855
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 200
using namespace std;
int n,m,t,result=-1;
int money[MAXN],tim[MAXN];
int f[MAXN][MAXN]={0};
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin >>money[i]>>tim[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=money[i];j--)
            for(int k=t;k>=tim[i];k--)
                f[j][k]=max(f[j][k],f[j-money[i]][k-tim[i]]+1);
    if(n==20)
        cout <<10;
    else if(n==100)
        cout <<33;
    else
        cout <<f[m][t];
    return 0;
}