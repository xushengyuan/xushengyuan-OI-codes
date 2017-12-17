#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#define MAXN 50000
using namespace std;
int m,n,q;
int f[MAXN/5];
vector<pair<int,int> > _map[MAXN/5];
int dad[MAXN/5],depth[MAXN/5];
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
void dfs(int x,int dep)
{
    depth[x]=dep;
    for(int i=0;i<_map[x].size();i++)
    {
        dad[_map[x][i].first]=x;
        dfs(_map[x][i].first,dep+1);
    }
    return ;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;i++)
        edges[i].u=read_int(),edges[i].v=read_int(),edges[i].w=read_int();
    for(int i=1;i<=n;i++)
        f[i]=i;
    sort(edges,edges+n,cmp);
    int tot=0,p=0;
    un(edges[0]);
    tot++,p++;
    while(tot<n-1)
        if(find(edges[p].u)!=find(edges[p].v))
        {
            tot++,p++;
            un(edges[p]);
        }
        else
        {
            p++;
        }
    for(int i=1;i<=n;i++)
    {
        dad[i]=-1;
        depth[i]=0;
    }
    dfs(rand()%n+1,0);
    for(int i=1;i<=n;i++)
        cout<<i<<dad[i]<<endl;
    return 0;
}