//Date:2018/2/17
//OJ:luogu
//Problem:1038
//Solution:Topsort
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 110
//#define _DEBUG
using namespace std;
vector<pair<int,int> >_map[MAXN];
int bais[MAXN],n,p,point[MAXN],in[MAXN],out[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(point,0,sizeof(point));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    cin>>n>>p;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        point[i]=x;
        bais[i]=y;
    }
    for(int i=0;i<p;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        _map[u].push_back(make_pair(v,w));
        out[u]++;
        in[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i]==0)
        {
            q.push(i);
            bais[i]=0;
        }
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<_map[p].size();i++)
        {
            int v=_map[p][i].first,w=_map[p][i].second;
            in[v]--;
            if(point[p]-bais[p]>0)
                point[v]+=(point[p]-bais[p])*w;
            if(in[v]==0)
                q.push(v);
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(out[i]==0)
        {
            point[i]-=bais[i];
            if(point[i]>0)
            {
                cout<<i<<' '<<point[i]<<endl;
                flag=false;
            }
            else if(point[i]<0)
                flag=false;
        }
    }
    if(flag)
        cout<<"NULL"<<endl;
    return 0;
}