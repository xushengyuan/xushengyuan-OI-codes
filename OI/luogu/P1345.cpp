//Date:2018/9/7
//OJ:luogu
//Problem:1345
//Solution:Dinic
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define INF 0x3fffffff
#define MAXN 210
using namespace std;
int n,m,c1,c2;
int dep[MAXN];
inline int read_int()
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
struct node
{
    int v,w,r;
};
vector<node>g[MAXN];
queue<int>Q;
int dfs(int p,int t)
{
    if(p==c2)
        return t;
    int sum=0;
    for(int i=0;i<g[p].size();i++)
    {
        node edge=g[p][i];
        int v=edge.v;
        if(edge.w>0 && dep[v]==dep[p]+1)
        {
            int vt=dfs(v,min(t,edge.w));
            g[p][i].w-=vt;
            g[v][edge.r].w+=vt;
            t-=vt;
            sum+=vt;
            if(!t)break;
        }
    }
    return sum;
}
bool bfs()
{
    memset(dep,0,sizeof(dep));
    dep[c1]=1;
    Q.push(c1);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            node edge=g[u][i];
            int v=edge.v;
            if(edge.w!=0 && dep[v]==0)
            {
                dep[v]=dep[u]+1;
                Q.push(v);
            }
        }
    }
    if(dep[c2]!=0)
        return true;
    else
        return false;
}
inline void addedge(int u,int v,int w)
{
    g[u].push_back({v,w,g[v].size()});
    g[v].push_back({u,0,g[u].size()-1});
    return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m>>c1>>c2;
    for(int i=1;i<=n;i++)
        addedge(i,i+n,(i!=c1 && i!=c2)?1:INF);
    for(int i=1;i<=m;i++)
    {
        int u=read_int(),v=read_int();
        addedge(u+n,v,INF);
        addedge(v+n,u,INF);
    }

    int result=0;
    // for(int i=1;i<=2*n;i++)
    // {
    //     for(int j=0;j<g[i].size();j++)
    //         cout<<g[i][j].w<<' ';
    //     cout<<endl;
    // }
    while(bfs())
        result+=dfs(c1,INF);
    cout<<result<<endl;
    // for(int i=1;i<=2*n;i++)
    // {
    //     for(int j=0;j<g[i].size();j++)
    //         cout<<g[i][j].w<<' ';
    //     cout<<endl;
    // }
    return 0;
}