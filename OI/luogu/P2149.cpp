//Date:2018/9/8/
//OJ:luogu
//Problem:2149
//Solution:SPFA+Topo
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define INF 0x3fffffff
#define MAXN 1510
using namespace std;
int n,m;
int x1,y11,x2,y2;
int dis[4][MAXN],in[3][MAXN];
vector<pair<int,int> > g[3][MAXN];
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
inline void addedge(int gid,int u,int v,int w)
{
    g[gid][u].push_back({v,w});
    if(gid==0)
        g[gid][v].push_back({u,w});
    if(gid>0)
        in[gid][v]++;
}
void spfa(int gid,int s)
{
    queue<int>Q;
    Q.push(s);
    bool visit[MAXN];
    memset(visit,0,sizeof(visit));
    memset(dis[gid],0x3f,sizeof(dis[gid]));
    dis[gid][s]=0;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int i=0;i<g[0][u].size();i++)
        {
            int v=g[0][u][i].first,w=g[0][u][i].second;
            if(dis[gid][u]+w<dis[gid][v])
            {
                dis[gid][v]=dis[gid][u]+w;
                if(!visit[v])
                {
                    visit[v]=true;
                    Q.push(v);
                }
            }
        }
    }
}
int topo(int gid)
{
    int length[MAXN];
    memset(length,0,sizeof(length));
    queue<int>Q;
    for(int i=1;i<=n;i++)
        if(!in[gid][i])
            Q.push(i);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int j=0;j<g[gid][u].size();j++)
        {
            int v=g[gid][u][j].first,w=g[gid][u][j].second;
            in[gid][v]--;
            length[v]=max(length[u]+w,length[v]);
            if(!in[gid][v])
                Q.push(v);
        }
    }
    int Max=0;
    for(int i=1;i<=n;i++)
        Max=max(Max,length[i]);
    return Max;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    cin>>x1>>y11>>x2>>y2;
    for(int i=0;i<m;i++)
    {
        int u=read_int(),v=read_int(),w=read_int();
        addedge(0,u,v,w);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<g[0][i].size();j++)
    //         cout<<g[0][i][j].first<<' ';
    //     cout<<endl;
    // }   
    spfa(0,x1);
    spfa(1,y11);
    spfa(2,x2);
    spfa(3,y2);
    memset(in,0,sizeof(in));
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[0][i].size();j++)
            if(dis[0][i]+g[0][i][j].second+dis[1][g[0][i][j].first]==dis[0][y11])
            {
                if(dis[2][i]+g[0][i][j].second+dis[3][g[0][i][j].first]==dis[2][y2])
                    addedge(1,i,g[0][i][j].first,g[0][i][j].second);
                else if(dis[3][i]+g[0][i][j].second+dis[2][g[0][i][j].first]==dis[2][y2])
                    addedge(2,i,g[0][i][j].first,g[0][i][j].second);
            }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<g[2][i].size();j++)
    //         cout<<g[2][i][j].first<<' ';
    //     cout<<endl;
    // }   
    cout<<max(topo(1),topo(2));
    return 0;
}