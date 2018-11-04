//Date:2018/9/23
//OJ:luogu
//Problem:1993
//Solution:SPFA
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define INF 0x3fffffff
#define MAXN 10010
using namespace std;
int n,m;
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
vector<pair<int,int> >g[MAXN];
int dis[MAXN],vis[MAXN];
int flag=true;
void SPFA(int u)
{
    vis[u]=true;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].first,w=g[u][i].second;
        if(dis[v]>dis[u]+w)
        {
            if(vis[v])
            {
                flag=false;
                return;
            }
            dis[v]=dis[u]+w;
            SPFA(v);
            if(!flag)
            {
                cout<<"No";
                exit(0);
            }
        }
    }
    vis[u]=false;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int f=read_int(),a=read_int(),b=read_int();
        switch (f)
        {
        case 1:
            g[a].push_back({b,-1*read_int()});
            break;
        case 2:
            g[b].push_back({a,read_int()});
            break;
        case 3:
            g[a].push_back({b,0});
            g[b].push_back({a,0});
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=0;
        SPFA(i);
    }
    cout<<"Yes";
    return 0;
}