//Date:2017/9/20
//OJ:luogu
//Problem:1514
//Solution: DP+BFS
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 510
using namespace std;
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

int n,m;
int data[MAXN][MAXN],f[MAXN];
bool vis[MAXN][MAXN];
pait<int,int> segs[MAXN];
queue<pair<int,int> > q;
inline void BFS()
{
    int px,py;
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        vis[p.first][p.second]=true;
        cout <<p.first<<' '<<p.second<<endl;
        px=p.first+1,py=p.second;
        if(px<n && !vis[px][py] && data[px][py]<data[p.first][p.second])
            q.push({px,py});
        px=p.first,py=p.second+1;
        if(py<m && py>=0&& !vis[px][py] && data[px][py]<data[p.first][p.second])
            q.push({px,py});
        px=p.first,py=p.second-1;
        if(py<m && py>=0&& !vis[px][py] && data[px][py]<data[p.first][p.second])
            q.push({px,py});
    }
    return ;
}
inline void vis_out()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout <<vis[i][j]<<' ';
        cout <<endl;
    }
}
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            data[i][j]=read_int();
    for(int i=0;i<m;i++)
        q.push({0,i});
    //q.push({0,5});
    BFS();
    int tot=0;
    for(int i=0;i<m;i++)
        if(!vis[n-1][i])
            tot++;
    if(tot!=0)
    {
        cout <<0<<endl<<tot;
        exit(0);
    }
    else
    {

    }
    return 0;
}