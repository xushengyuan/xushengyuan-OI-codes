//Date:2018/8/5
//OJ:luogu
//Problem:1346
//Solution:floyd
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 110
#define _DEBUG
int g[MAXN][MAXN];
int n,a,b;
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>a>>b;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        int t,tmp;
        cin>>t;
        g[i][i]=0;
        for(int j=1;j<=t;j++)
        {
            cin>>tmp;
            if(j==1)
                g[i][tmp]=0;
            else
                g[i][tmp]=1;
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)   
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    if(g[a][b]==0x3f3f3f3f)
        cout<<-1;
    else
        cout<<g[a][b];
    return 0;
}