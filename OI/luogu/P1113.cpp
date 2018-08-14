//Date:2018/8/13
//OJ:luogu
//Problem:1113
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10001
using namespace std;
int n,data[MAXN],in[MAXN],out[MAXN],t[MAXN];
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
    cin>>n;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(t,0,sizeof(out));
    for(int i=1;i<=n;i++)
    {
        int id=read_int();
        data[id]=read_int();
        int t=read_int();
        while(t!=0)
        {
            out[id]++;
            in[t]++;
            g[id].push_back(t);
            t=read_int();
        }
    }
    queue<int>Q;
    for(int i=1;i<=n;i++)   
        if(in[i]==0)
        {
            t[i]=data[i];
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
            t[v]=max(t[v],t[u]+data[v]);
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