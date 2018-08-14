//Date:2018/8/7
//OJ:luogu
//Problem:1144
//Solution:BFS
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000000
#define MOD 100003
#define _DEBUG
using namespace std;
int n,m;
int dis[MAXN],cot[MAXN];
bool vis[MAXN];
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(cot,0,sizeof(cot));
    memset(vis,0,sizeof(vis));
    memset(dis,0x37,sizeof(dis));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u=read_int(),v=read_int();
        if(u==v)
            continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=true;
    cot[1]=1;
    dis[1]=0;
    queue<pair<int,int> >Q;
    Q.push({1,1});
    while(!Q.empty())
    {
        pair<int,int> p=Q.front();
        Q.pop();
        for(int i=0;i<g[p.first].size();i++)
            if(!vis[g[p.first][i]])
            {
                dis[g[p.first][i]]=p.second+1;
                vis[g[p.first][i]]=true;
                cot[g[p.first][i]]=(cot[g[p.first][i]]+cot[p.first])%MOD;
                Q.push({g[p.first][i],p.second+1});
            }
            else if(dis[g[p.first][i]]==p.second+1)
                cot[g[p.first][i]]=(cot[g[p.first][i]]+cot[p.first])%MOD;
    }
    for(int i=1;i<=n;i++)
        cout<<cot[i]<<endl;
    return 0;
}