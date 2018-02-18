//Date:2018/2/16
//OJ:luogu
//Problem:1141
//Solution:BFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1002
using namespace std;
bool data[MAXN][MAXN];
const int _move[10][10]={{0,-1},{0,1},{1,0},{-1,0}};
int mem[MAXN][MAXN];
bool visit[MAXN][MAXN];
int n,m;
bool get_pixel()
{
    char t;
    t=getchar();
    while(t!='0' && t!='1')
        t=getchar();
    return t=='1'?true:false;
}
vector<pair<int,int> >tmp;
void dfs(int x,int y)
{
    bool p=data[x][y];
    visit[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int px=x+_move[i][0];
        int py=y+_move[i][1];
        if(px<0 || py<0 || px>=n || py>=n || visit[px][py]) 
            continue;
        if(p!=data[px][py])
        {
            tmp.push_back({px,py});
            //cout<<tmp.size()<<' '<<px<<' '<<py<<endl;
            dfs(px,py);
        }
    }
    return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(mem,0,sizeof(mem));
    memset(visit,0,sizeof(visit));
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            data[i][j]=get_pixel();
    for(int k=0;k<m;k++)
    {
    int src_x,src_y;src_y--;
        cin>>src_x>>src_y;
        src_x--;
        src_y--;
        if(mem[src_x][src_y]==0)
        {
            tmp.clear();
            tmp.push_back({src_x,src_y});
            dfs(src_x,src_y);
            for(int i=0;i<tmp.size();i++)
                mem[tmp[i].first][tmp[i].second]=tmp.size();
        }
        cout<<mem[src_x][src_y]<<endl;
    }
    return 0;
}
