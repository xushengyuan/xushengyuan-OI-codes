//Date:2017/8/24
//OJ:luogu
//Problem:1346
//Solution:Dijkstra
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int n,a,b,m=0;
vector<int> _map[110];
struct edge
{
    int u,v,w;
}edges[20100];
struct point
{
    int n,d=0x7fffffff;
};
bool operator < (const point &a,const point &b)
{
    return a.d>b.d;
}
priority_queue<point> q;
int d[110]={0x7fffffff};
bool visit[110]={false};
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    //#endif
    cin >>n>>a>>b;
    a--;
    b--;
    fill(d,d+110,0x7fffffff);
    for(int i=0;i<n;i++)
    {
        int t;
        edge tmp;
        cin >>t;
        tmp.u=i;
        if(t>0)
            for(int j=0;j<t;j++)
            {
                cin >>tmp.v;
                tmp.v--;
                if(j==0)
                    tmp.w=0;
                else
                    tmp.w=1;
                _map[tmp.u].push_back(m);
                //cout <<_map[tmp.u].size()<<endl;
                edges[m++]=tmp;
                if(tmp.u!=tmp.v)
                {
                    tmp.u=tmp.v;
                    tmp.v=i;
                    tmp.w=1;
                    _map[tmp.u].push_back(m);
                    edges[m++]=tmp;
                }
            } 
    }
    point t_p;
    t_p.n=a;
    t_p.d=0;
    d[a]=0;
    q.push(t_p);
    while(!q.empty())
    {
        point p=q.top();
        cout <<p.d<<' ';
        q.pop();
        if(!visit[p.n])
        {
            visit[p.n]=true;
            for(int i=0;i<_map[p.n].size();i++)
            {
                if(p.d+(i!=0) < d[edges[_map[p.n][i]].v])
                { 
                    d[edges[_map[p.n][i]].v]=p.d+(i!=0);
                    cout <<i<<endl;
                    t_p.n=edges[_map[p.n][i]].v;
                    t_p.d=d[edges[_map[p.n][i]].v];
                    q.push(t_p);
                }
            }
        }
    }
    cout <<endl;
    if(d[b]==0x7fffffff)
        cout<<-1;
    else
        cout <<d[b];
    return 0;
}

