#include<bits/stdc++.h>
#define MAXN 50000
#define INT_INF 0x7fffffff
using namespace std;
vector<pair<int,int> > _map[MAXN];
long long n,m,b;
int data[MAXN];
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
void add_edge(int u,int v,int w)
{
    _map[u].push_back(make_pair(v,w));
    _map[v].push_back(make_pair(u,w));
    return ;
}
long long dis[MAXN];
int sum=0;
bool vis[MAXN];
queue<int> q;
bool spfa(long long max_money)
{
    while(!q.empty())
        q.pop();
    /*for(int i=1;i<=n;i++)
    {
        dis[i]=1234567890;
        vis[i]=false;
        //cout << dis[i]<<endl;
    }*/
    memset(dis,0x7f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    //cout<<max_money;
    q.push(1);
    vis[1]=true;
    dis[1]=0;
    while(!q.empty())
    {
        //cout <<q.size()<<endl;
        int p=q.front();
        q.pop();
        vis[p]=false;
        for(int i=0;i<_map[p].size();i++)
        {
            pair<int ,int> v=_map[p][i];
            //cout <<dis[v.first]<<' '<<dis[p] + v.second<<endl;
            //if(data[v.first] > max_money)   continue;
            if(dis[v.first] > dis[p] + v.second&&data[v.first]<=max_money)
            {
                dis[v.first]=dis[p] + v.second;
                if(!vis[v.first])
                {
                    vis[v.first]=true;
                    q.push(v.first);
                }
            }
        }
    }
    //cout <<'|'<<dis[n]<<endl;
    if(dis[n] >= b )
        return false;
    else
        return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >>n>>m>>b;
    for(int i=1;i<=n;i++)
        data[i]=read_int();
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        u=read_int();
        v=read_int();
        w=read_int();
        add_edge(u,v,w);
    }
    //sort(data+1 ,data+1+n);
    int r,l,mid,result=-1;
    for(int i=1;i<=n;i++)
        l=min(l,data[i]),r=max(r,data[i]);
    if(!spfa(0x7f7f7f7f7f))
    {
        cout <<"AFK";
        exit(0);
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        //cout <<l<<' '<<r<<endl;
        if(spfa(mid))
        {
            result=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(result == -1)
        cout <<"AFK";
    else
        cout <<result;
    return 0;
}
