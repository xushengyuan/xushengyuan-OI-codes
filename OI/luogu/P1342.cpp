//Date:2017/10/3
//OJ:luogu
//Problem:1342
//Solution:Diji
//By:xushengyuan
#include <bits/stdc++.h>
#define il inline
#define ll long long 
#define re register
#define INT_INF 0x7fffffff
#define MAXN 1000010
using namespace std;
int n,m;
vector<pair<int,int> >_map[MAXN],_map_rv[MAXN];
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

il ll dij1()
{
    ll ans;
    bool vis[MAXN];
    int dis[MAXN];
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dis[i]=INT_INF;
    }
    vector<pair<int,int> > heap;
    dis[1]=0;
    vis[1]=true;
    heap.push_back({0,1});
    make_heap(heap.begin(),heap.end());
    while(!heap.empty())
    {
        pair<int,int> p=heap.front();
        pop_heap(heap.begin(),heap.end());
        heap.pop_back();
        dis[p.second]=p.first;
        for(int i=0;i<_map[p.second].size();i++)
        {
            if(!vis[_map[p.second][i].first] && p.first+_map[p.second][i].second < dis[_map[p.second][i].first])
            {
                vis[_map[p.second][i].first]=true;
                heap.push_back({p.first+_map[p.second][i].second,_map[p.second][i].first});
                push_heap(heap.begin(),heap.end());
            }
        }
    }
    for(int i=2;i<=n;i++)
        ans+=dis[i];
    return ans;
}
il ll dij2()
{
    ll ans;
    bool vis[MAXN];
    int dis[MAXN];
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dis[i]=INT_INF;
    }
    vector<pair<int,int> > heap;
    dis[1]=0;
    vis[1]=true;
    heap.push_back({0,1});
    make_heap(heap.begin(),heap.end());
    while(!heap.empty())
    {
        pair<int,int> p=heap.front();
        pop_heap(heap.begin(),heap.end());
        heap.pop_back();
        dis[p.second]=p.first;
        for(int i=0;i<_map_rv[p.second].size();i++)
        {
            if(!vis[_map_rv[p.second][i].first] && p.first+_map_rv[p.second][i].second < dis[_map[p.second][i].first])
            {
                vis[_map_rv[p.second][i].first]=true;
                heap.push_back({p.first+_map_rv[p.second][i].second,_map_rv[p.second][i].first});
                push_heap(heap.begin(),heap.end());
            }
        }
    }
    for(int i=2;i<=n;i++)
        ans+=dis[i];
    return ans;

}
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        u=read_int();
        v=read_int();
        w=read_int();
        _map[u].push_back({v,w});
        _map_rv[v].push_back({u,w});
    }
    ll ans;
    ans=dij1()+dij2();
    cout<<ans;
    return 0;
}