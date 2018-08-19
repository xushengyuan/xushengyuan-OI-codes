//Date:2018/8/16
//OJ:luogu
//Problem:3779
//Solution:LCA
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 500100
using namespace std;
int n,m,s;
int depth[MAXN],fa[MAXN][21];
vector<int>g[MAXN];
int read_int()
{
    int result=0;
    char t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
void dfs(int p,int f)
{
    depth[p]=depth[f]+1;
    fa[p][0]=f;
    for(int i=1;(1<<i)<=depth[p];i++)
        fa[p][i]=fa[fa[p][i-1]][i-1];
    for(int i=0;i<g[p].size();i++)
        if(g[p][i]!=f)
            dfs(g[p][i],p);
    return ;
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    for(int i=20;i>=0 ;i--)
        if(depth[b]<=depth[a]-(1<<i))
            a=fa[a][i];
    if(a==b)
        return b;
    for(int i=20;i>=0 ;i--)
        if(fa[a][i]!=fa[b][i])
            a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(fa,0,sizeof(fa));
    memset(depth,0,sizeof(depth));
    cin>>n>>m>>s;
    for(int i=1;i<=n-1;i++)
    {
        int u=read_int(),v=read_int();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        int a=read_int(),b=read_int();
        printf("%d\n",lca(a,b));
    }
    return 0;
}