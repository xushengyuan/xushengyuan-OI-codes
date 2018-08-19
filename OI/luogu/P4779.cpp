//Date:2018/8/15
//OJ:luogu
//Problem:4779
//Solution:Dijkstra
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 100010
using namespace std;
vector< pair<int,int> > _map[MAXN];
int dis[MAXN];
bool visit[MAXN];
int n,m,s;
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
struct node
{
    int u,dis;
};
bool operator <(const node a,const node b)
{
    return a.dis>b.dis;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    for(int i=0;i<MAXN;i++)
        dis[i]=1e10;
    memset(visit,0,sizeof(visit));
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        //int u=read_int(),v=read_int(),w=read_int();
        int u,v,w;
        cin>>u>>v>>w;
        _map[u].push_back(make_pair(v,w));
    }
    dis[s]=0;
    visit[s]=true;
    priority_queue<node>heap;
    heap.push({s,0});
    while(!heap.empty())
    {
        int u=heap.top().u;
        heap.pop();
        visit[u]=false;
        for(int i=0;i<_map[u].size();i++)
        {
            int v=_map[u][i].first,w=_map[u][i].second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                if(!visit[v])
                {
                    heap.push({v,dis[v]});
                    visit[v]=true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<' ';
    return 0;

}