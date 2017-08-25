//Date:2017/8/12
//OJ:luogu
//Problem:1330
//Solution:BFS+dye
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
bool vis[MAXN]={false};
int clor[MAXN]={-1};
int n,m;
vector<int> node[MAXN];
int bfs(int p)
{
    queue<int> q;
    q.push(p);
    vis[p]=true;
    clor[p]=1;
    int cout0=0,cout1=1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        //cout <<p+1<<' '<<clor[p]<<'|';
        int node_size=node[p].size();
        for(int i=0;i<node_size;i++)
        {
            int next=node[p][i];
            //cout <<vis[next]<<'^';
            if(vis[next])
            {
                if(clor[next]==clor[p]) 
                    return -1;
            }
            else
            {
                vis[next]=true;
                clor[next]=clor[next]=clor[p]?0:1;
                q.push(next);
                cout0+=clor[next]?0:1;
                cout1+=clor[next]?1:0;
                //cout <<clor[next]<<' ';
            }
        }
        //cout <<endl;
    }
    return min(cout0,cout1);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>m;
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin >>a>>b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int ans=0,t;
    for(int i=0;i<n;i++)
        if(!vis[i])
        {
            t=bfs(i);
            if(t!=-1)
                ans+=t;
            else
            {
                cout <<"Impossible"<<endl;
                exit(0);
            }
        }
    cout <<ans;
    return 0;
}