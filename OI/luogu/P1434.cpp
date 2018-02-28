//Ver 1
//Date:2017/10/14   
//OJ:luogu
//Problem:1434
//Solution:DP
//By:xushengyuan
// #include <bits/stdc++.h>
// #define MAXN 120
// using namespace std;
// int read_int()
// {
//         int result=0;
//     char t;
//     t=getchar();
//     while(!isdigit(t))
//       t=getchar();
//     while(isdigit(t))
//     {
//         result=result*10+t-'0';
//             t=getchar();
//     }
//         return result;
// }
// struct point
// {
//     int x;  
//     int y;
//     int h;
// };
// int f[MAXN][MAXN];
// int r,c;
// int data[MAXN][MAXN];
// const int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
// int main()
// {
// //#ifdef _DEBUG
//     //freopen("in.txt","r",stdin);
//     //freopen("out.txt","w",stdout);
// //#endif
//     cin>>r>>c;
//     int min_h=0x7fffffff,min_x,min_y;
//     for(int i=0;i<r;i++)
//         for(int j=0;j<c;j++)
//             cin>>data[i][j];
//     for(int i=0;i<r;i++)
//         for(int j=0;j<c;j++)
//             f[i][j]=0;
//     queue<point> q;
//     q.push({min_x,min_y,1});
//     f[min_x][min_y]=1;
//     //cout<<min_x<<' '<<min_y<<endl;
//     int px,py,tot=0;
//     while(!q.empty())
//     {
//         point p=q.front();
//         q.pop();
//         f[min_x][min_y]=max(f[min_x][min_y],p.h);
//         for(int i=0;i<4;i++)
//         {
//             px=p.x+mov[i][0],py=p.y+mov[i][1];
//             if(px>=0 && px<r && py>=0 && py<c && data[px][py]>data[p.x][p.y] && (f[px][py]<f[p.x][p.y] || f[px][py]==0))
//             {
//             	//cout<<px<<' '<<py<<endl;
//             	//cout<<tot++<<endl;
//                 if(f[px][py]!=0)
//                 	f[min_x][min_y]=max(f[min_x][min_y],f[px][py]+p.h);
//                 else
//                 	q.push({px,py,p.h+1});
                
//             }
//         }
//     }   
//     int _max=-1;
//     for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//             //cout<<f[i][j]<<' ';
//             _max=max(f[i][j],_max);
//     	}
//         //cout<<endl;
//     }
//     cout<<_max<<endl;
//     return 0;
// }
//Ver 2
//Date:2018/2/20
//OJ:luogu
//Problem:1434
//Solution:DFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
using namespace std;
int f[MAXN][MAXN];
int data[MAXN][MAXN];
int r,c;
const int kotori[5][5]={{0,1},{0,-1},{1,0},{-1,0}};
int dfs(int x,int y)
{
    if(f[x][y]!=0)
        return f[x][y];
    else
    {
        f[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int px=x+kotori[i][0],py=y+kotori[i][1];
            if(px>=r || py>=c || px<0 || py<0)
                continue;
            if(data[px][py]<data[x][y])
                f[x][y]=max(f[x][y],dfs(px,py)+1);
        }
        return f[x][y];
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(f,0,sizeof(f));
    cin>>r>>c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>data[i][j];
    int _max=-1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            _max=max(_max,dfs(i,j));
            // for(int i=0;i<r;i++)
            // {
            //     for(int j=0;j<c;j++)
            //         cout<<f[i][j]<<' ';
            //     cout<<endl;
            // }
            // cout<<endl;
        }
    cout<<_max;
    return 0;
}