//Date:2018/3/4
//OJ:luogu
//Problem:1784
//Solution:DFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int data[10][10];
bool _data[10][10];
int _max=-1;
bool a[10][10],b[10][10],c[10][10];
const int pos[10][10]=
{
    {1,1,1,2,2,2,3,3,3},
    {1,1,1,2,2,2,3,3,3},
    {1,1,1,2,2,2,3,3,3},
    {4,4,4,5,5,5,6,6,6},
    {4,4,4,5,5,5,6,6,6},
    {4,4,4,5,5,5,6,6,6},
    {7,7,7,8,8,8,9,9,9},
    {7,7,7,8,8,8,9,9,9},
    {7,7,7,8,8,8,9,9,9}
};
const int points[10][10]=
{
    {6,6,6,6,6,6,6,6,6},
    {6,7,7,7,7,7,7,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,9,10,9,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,7,7,7,7,7,7,6},
    {6,6,6,6,6,6,6,6,6}
};
void dfs(int x,int y)
{
    // for(int i=1;i<=9;i++)
    // {
    //     for(int j=1;j<=9;j++)
    //         cout<<data[i][j]<<' ';
    //     cout<<endl;
    // }
    // cout<<endl;
    if(data[x][y]!=0)
    {
        if(x==1&&y==9) 
        {
            int sum=0;
            for(register int i=1;i<=9;i=-(~i))
                for(register int j=1;j<=9;j=-(~j))
                    sum+=_data?points[i-1][j-1]*data[i][j]:0;
            _max=max(_max,sum);
        }
        if(y==9) 
            dfs(x-1,1); 
        else
            dfs(x,y+1);
    }
    else 
    {
        for(int k=9;k>=1;k--)
        {
            if(a[x][k])continue;
            if(b[y][k])continue;
            if(c[pos[x-1][y-1]][k])continue;
            data[x][y]=k;
            if(x==1&&y==9) 
            {
                int sum=0;
                for(register int i=1;i<=9;i=-(~i))
                    for(register int j=1;j<=9;j=-(~j))
                        sum+=_data?points[i-1][j-1]*data[i][j]:0;
                _max=max(_max,sum);
            }
            a[x][k]=true;
            b[y][k]=true;
            c[pos[x-1][y-1]][k]=true;
            dfs(y==9?x-1:x,y==9?1:y+1);
            data[x][y]=0;
            a[x][k]=false;
            b[y][k]=false;
            c[pos[x-1][y-1]][k]=false;
        }
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(_data,0,sizeof(_data));
    for(register int i=1;i<=9;i=-(~i))
        for(register int j=1;j<=9;j=-(~j))
        {
            cin>>data[i][j];
            _data[i][j]=data[i][j]==0?true:false;
            a[i][data[i][j]]=true;
            b[j][data[i][j]]=true;
            c[pos[i-1][j-1]][data[i][j]]=true;
        }
    dfs(9,1);
    cout<<_max;
    return 0;
}