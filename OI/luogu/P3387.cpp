//Date:2018/10/8
//OJ:luogu
//Problem:3387
//Solution: tarjan+topo
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10010
#define MAXM 100010
using namespace std;
int n,m;
int weight[MAXN];
vector<int>g[MAXN],g2[MAXN];
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
int dfn[MAXN],low[MAXN],belong[MAXN];
stack<int>S;
bool inStack[MAXN];
int p=0,cot=0;
void tarjan(int u)
{
    p++;
    dfn[u]=p;
    low[u]=dfn[u];
    S.push(u);
    inStack[u]=true;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(dfn[v]==0)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v] && dfn[v]<low[u])
            low[u]=dfn[v];
    }
    if(dfn[u]==low[u])
    {
        cot++;
        while(S.top()!=u)
        {
            int top=S.top();
            inStack[top]=false;
            belong[top]=u;
            weight[u]+=weight[top];
            S.pop();
        }
        int top=S.top();
        inStack[top]=false;
        belong[top]=u;
        // weight[u]+=weight[top];
        S.pop();
    }
}
int from[MAXM],to[MAXM];
int dis[MAXN],in[MAXN];
int topo()
{
    memset(dis,0,sizeof(dis));
    queue<int>Q;
    for(int i=1;i<=n;i++)
        if(belong[i]==i&&in[i]==0)
        {
            dis[i]=weight[i];
            Q.push(i);
        }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<g2[u].size();i++)
        {
            int v=g2[u][i];
            dis[v]=max(dis[v],dis[u]+weight[v]);
            in[v]--;
            if(in[v]==0)
                Q.push(v);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dis[i]);
    return ans;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        weight[i]=read_int();
    for(int i=0;i<m;i++)
    {
        int u=read_int(),v=read_int();
        g[u].push_back(v);
        from[i]=u;
        to[i]=v;
    }
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(inStack,0,sizeof(inStack));
    for(int i=1;i<=n;i++)
        if(dfn[i]==0)
            tarjan(i);
    memset(in,0,sizeof(in));
    for(int i=0;i<m;i++)
    {
        int u=belong[from[i]],v=belong[to[i]];
        if(u!=v)
        {
            g2[u].push_back(v);
            // cout<<u<<' '<<v<<endl;
            in[v]++;
        }
    }
    int result=topo();
    cout<<result;
    return 0;
}