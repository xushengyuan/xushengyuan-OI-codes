//Date:2018/2/10
//OJ:luogu
//Problem:1525
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000100
#define _DEBUG
using namespace std;
int n,m;
struct edge
{
    int u,v,w;
}edges[MAXN];
bool operator <(edge a,edge b)
{
    return a.w>b.w;
}
int data[MAXN],_less[MAXN];
int find(int x)
{
    return data[x]==x?x:data[x]=find(data[x]);
}
void uni(int x,int y)
{
    data[find(y)]=find(x);
    return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for (int i = 0; i < m; i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges,edges+m);
    int p=0;
    for(int i=1;i<=n;i++)
    {
        data[i]=i;
        _less[i]=-1;
    }
    while(p<m)
    {
        if(find(edges[p].u)!=find(edges[p].v))
        {
            if(_less[edges[p].u]!=-1)
                uni(edges[p].v,_less[edges[p].u]);
            else
                _less[edges[p].u]=edges[p].v;
            if(_less[edges[p].v]!=-1)
                uni(edges[p].u,_less[edges[p].v]);
            else
                _less[edges[p].v]=edges[p].u;
        }
        else
        {
            cout<<edges[p].w<<endl;
            return 0;
        }
        p++;
    }
    cout<<0;
    return 0;
}