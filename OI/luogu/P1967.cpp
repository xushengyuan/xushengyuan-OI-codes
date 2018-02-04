#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cmath>
#define MAXN 60000
using namespace std;
int m,n,q;
int f[MAXN];
vector<pair<int,int> > _map[MAXN];
int dad[MAXN],depth[MAXN];
struct edge
{
    int u,v,w;
}edges[MAXN];
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
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(edge a,edge b)
{
    return a.w>b.w;
}
void un(edge x)
{
    f[find(x.u)]=find(x.v);
    _map[x.u].push_back(make_pair(x.v,x.w));
    _map[x.v].push_back(make_pair(x.u,x.w));
    return ;
}
bool visit[MAXN];
int dad_weight[MAXN];
void dfs(int x,int dep)
{
    depth[x]=dep;
    visit[x]=true;
    for(int i=0;i<_map[x].size();i++)
    {
        if(visit[_map[x][i].first])
            continue;
        dad[_map[x][i].first]=x;
        dad_weight[_map[x][i].first]=_map[x][i].second;
        dfs(_map[x][i].first,dep+1);
    }
    return ;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        edges[i].u=read_int(),edges[i].v=read_int(),edges[i].w=read_int();
        //cout<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
    }
    for(int i=1;i<=m;i++)
        f[i]=i;
    sort(edges,edges+m,cmp);
    int tot=0,p=0;
    while(tot<n-1 && p<m)
        if(find(edges[p].u)!=find(edges[p].v))
        {
            un(edges[p]);
            tot++,p++;
        }
        else
        {
            p++;
        }
    for(int i=1;i<=n;i++)
    {
        dad[i]=-1;
        depth[i]=0;
        visit[i]=false;
    }
    //for(int i=1;i<=n;i++)
    //    cout<<i<<' '<<f[i]<<endl;
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<_map[i].size();j++)
            cout<<_map[i][j].first<<' ';
        cout<<endl;
    }*/
    dfs(rand()%n+1,0);
    //for(int i=1;i<=n;i++)
    //    cout<<i<<' '<<depth[i]<<endl;

    int dep_u,dep_v;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int u=read_int(),v=read_int(),ans=0x7fffffff;
        if(find(u)!=find(v))
        {
            cout<<-1<<endl;
            continue;
        }
        if(depth[u]<depth[v])
        {
            dep_u=depth[v],dep_v=depth[u];
            int t=u;
            u=v,v=t;
        }
        else
            dep_u=depth[u],dep_v=depth[v];
        int p=u,q=v;
        while(dep_u!=dep_v)
        {
            ans=min(ans,dad_weight[u]);
            p=dad[p];
            dep_u--;
        }
        while(p!=q)
        {
            ans=min(ans,dad_weight[u]);
            p=dad[p];
            dep_u--;
            ans=min(ans,dad_weight[v]);
            q=dad[v];
            dep_v--;
        }
        cout<<ans<<endl;
    }
    return 0;
}