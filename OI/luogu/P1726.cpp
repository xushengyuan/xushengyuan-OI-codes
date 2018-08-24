//Date:2018/8/21
//OJ:luogu
//Problem:1726
//Solution:Tarjan
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 5010
using namespace std;
int n,m,dfs_time=0,cnt=0;
vector<int>g[MAXN];
stack<int>s;
int pre[MAXN],low[MAXN],ans[MAXN],backup[MAXN];
bool vis[MAXN];
void tarjan(int u)
{
    dfs_time++;
    pre[u]=dfs_time;
    low[u]=dfs_time;
    s.push(u);
    vis[u]=true;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(pre[v]==0)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],pre[v]);
    }
    if(pre[u]==low[u])
    {
        vector<int>tmp;
        int p;
        do
        {
            p=s.top();
            vis[p]=false;
            tmp.push_back(p);
            s.pop();
            //cout<<p<<' ';
        }
        while(p!=u);
        //cout<<endl;
        cnt++;
        for(int i=0;i<tmp.size();i++)
            ans[tmp[i]]=cnt;
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(ans,0,sizeof(ans));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,f;
        scanf("%d%d%d",&u,&v,&f);
        if(f==1)
            g[u].push_back(v);
        else if(f==2)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }        
    }
    for(int i=1;i<=n;i++)
        if(pre[i]==0)
            tarjan(i);
    memcpy(backup,ans,sizeof(ans));
    sort(ans+1,ans+n+1);
    /*for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;*/
    int Max=-1,Maxn,p=0,last=-1;
    for(int i=1;i<=n;i++)
    {
        if(p==0)
        {
            last=ans[i];
            p++;
        }
        else if(last==ans[i])
            p++;
        else
        {
            if(p>Max)
            {
                Max=p;
                Maxn=last;
            }
            last=ans[i];
            p=1;
        }
    }
    if(p>Max)
    {
        Max=p;
        Maxn=last;
    }
    cout<<Max<<endl;
    for(int i=1;i<=n;i++)
        if(backup[i]==Maxn)
            cout<<i<<' ';
    
    return 0;
}