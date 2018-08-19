//Date:2018/8/8
//OJ:luogu
//Problem:1273
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 3010
using namespace std;
int n,m;
int data[MAXN],f[MAXN][MAXN];
struct Node
{
    int v,w;
};
vector<Node> g[MAXN];
int dfs(int u)
{
    if(u>n-m)
    {
        f[u][1]=data[u];
        return 1;
    }
    int s=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].v;
        int size=dfs(v);
        s+=size;
        for(int j=s;j>0;j--)
            for(int k=1;k<=size;k++)
                if(j>=k)
                    f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]-g[u][i].w);
    }
    return s;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=n-m;i++) 
    {
        int s;
        cin>>s;
        for(int j=1;j<=s;j++)
        {
            int u,w;
            cin>>u>>w;
            g[i].push_back({u,w});
        }
    }
    for(int i=n-m+1;i<=n;i++)
        cin>>data[i];
    memset(f,~0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
        f[i][0]=0;
    dfs(1);
    for(int i=m;i>=1;i--)
        if(f[1][i]>=0)
        {
            cout<<i;
            return 0;
        }
    return 0;
}