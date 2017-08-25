#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 1010
using namespace std;
int n,m;

char read()
{
    char t;
    t= getchar();
    while(!isalpha(t))
        t=getchar();
    return t;
}
struct point
{
    int x,y;
    char m;
}ma[MAXN][MAXN];
queue<point> q;
bool vis[MAXN][MAXN];
int main()
{
    cin >>n>>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ma[i][j].m=read();
            ma[i][j].x=i;
            ma[i][j].y=j;
        }
    fill(&vis[0][0],&vis[MAXN-1][MAXN-1],false);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if(ma[i][j].m=='o')
            {
                q.push(ma[i][j]);
                vis[i][j]=true;
            }
    point tmp;
    while(!q.empty())
    {
        tmp=q.front();
        /*for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                if(vis[i][j])
                    cout <<'1';
                else
                    cout <<'0';
            cout <<endl;
        }
        cout <<tmp.m<<endl;;*/
        q.pop();
        if(ma[tmp.x][tmp.y-1].m=='r' && !vis[tmp.x][tmp.y-1])
        {
            q.push(ma[tmp.x][tmp.y-1]);
            vis[tmp.x][tmp.y-1]=true;
        }
        if(ma[tmp.x][tmp.y+1].m=='l' && !vis[tmp.x][tmp.y+1])
        {
            q.push(ma[tmp.x][tmp.y+1]);
            vis[tmp.x][tmp.y+1]=true;
        }
        if(ma[tmp.x-1][tmp.y].m=='d' && !vis[tmp.x-1][tmp.y])
        {
            q.push(ma[tmp.x-1][tmp.y]);
            vis[tmp.x-1][tmp.y]=true;
        }
        if(ma[tmp.x+1][tmp.y].m=='u' && !vis[tmp.x+1][tmp.y])
        {
            q.push(ma[tmp.x+1][tmp.y]);
            vis[tmp.x+1][tmp.y]=true;
        }
    }
    int result=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if(vis[i][j]==true)
                result++;
    cout<<result;
    //system("pause");
}