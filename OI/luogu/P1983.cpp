//Date:2081/8/21
//OJ:luogu
//Problem:1983
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1010
using namespace std;
int n,m,in[MAXN],out[MAXN],t[MAXN];
bool vis[MAXN],gvis[MAXN][MAXN];
vector<int>g[MAXN];
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(t,0,sizeof(out));
    cin>>n>>m;
    memset(gvis,0,sizeof(gvis));
    for(int i=0;i<m;i++)
    {
        memset(vis,0,sizeof(vis));
        vector<int>s;
        int tot=read_int();
        int u=read_int();vis[u]=true;
        s.push_back(u);
        for(int j=0;j<tot-2;j++)
        {
            int tmp=read_int();
            s.push_back(tmp);
            vis[tmp]=true;
        }
        int v=read_int();vis[v]=true;
        s.push_back(v);
        for(int j=u;j<=v;j++)
            if(!vis[j])
                for(int k=0;k<s.size();k++)
                    if(!gvis[j][s[k]])
                    {
                        out[j]++;
                        in[s[k]]++;
                        g[j].push_back(s[k]);
                        gvis[j][s[k]]=true;
                    }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<' ';
        cout<<endl;
    }*/
    queue<int>Q;
    for(int i=1;i<=n;i++)   
        if(in[i]==0)
        {
            t[i]=1;
            Q.push(i);
        }
    int ans=-1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            t[v]=max(t[v],t[u]+1);
            ans=max(ans,t[v]);
            in[v]--;
            if(in[v]==0)
            {
                Q.push(v);
            }
        }
    }
    cout<<ans;
    return 0;
}