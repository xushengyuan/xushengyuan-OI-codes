//Date:2018/8/15
//OJ:luogu
//Problem:3385
//Solution: SPFA 
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 5100
using namespace std;
int dis[MAXN],cot[MAXN];
bool visit[MAXN];
int n,m,s;
int T;
bool spfa()
{
    vector< pair<int,int> > _map[MAXN];
    memset(cot,0,sizeof(cot));
    memset(dis,0x3f,sizeof(dis));
    memset(visit,0,sizeof(visit));
    cin>>n>>m;
    s=1;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        _map[u].push_back(make_pair(v,w));
        if(w>=0)
            _map[v].push_back(make_pair(u,w));
    }
    queue<int>q;
    q.push(s);
    cot[s]=1;
    dis[s]=0;
    visit[s]=true;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        visit[p]=false;
        for(int i=0;i<_map[p].size();i++)
        {
            if(_map[p][i].second+dis[p]<dis[_map[p][i].first])
            {
                dis[_map[p][i].first]=_map[p][i].second+dis[p];
                if(++cot[_map[p][i].first]>=n)
                    return true;
                if(visit[_map[p][i].first]==false)
                {
                    q.push(_map[p][i].first);
                    visit[_map[p][i].first]=true;
                }
            }
        }
    }
    return false;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>T;
    while(T--)
        cout<<(spfa()?"YE5":"N0")<<endl;
    return 0;
}