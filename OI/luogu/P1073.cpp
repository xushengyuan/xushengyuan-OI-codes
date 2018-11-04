//Date:2018/9/9
//OJ:luogu
//Problem:1073
//Solution:DFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10
using namespace std;
int n,m;
int price[MAXN],MinP[MAXN],f[MAXN];
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
void dfs(int p,int last,int Min)
{
    // cout<<p<<' '<<Min<<' '<<last<<endl;
    Min=min(Min,price[p]);
    int flag=0;
    if(Min<MinP[p])
    {
        MinP[p]=Min;
        flag++;
    }
    if(f[p]<max(price[p]-Min,f[last]))
    {
        f[p]=max(price[p]-Min,f[last]);
        flag++;
    }
    if(flag<=0)
        return ;
    for(int i=0;i<g[p].size();i++)
        dfs(g[p][i],p,Min);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(MinP,0x3f,sizeof(MinP));
    memset(f,0,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        price[i]=read_int();
    for(int i=1;i<=m;i++)
    {
        int u=read_int(),v=read_int(),flag=read_int();
        g[u].push_back(v);
        if(flag==2)
            g[v].push_back(u);
    }
    dfs(1,0,0x3fffffff);
    // for(int i=1;i<=n;i++)
    //     cout<<MinP[i]<<' '<<f[i]<<endl;
    cout<<f[n];
    return 0;
}