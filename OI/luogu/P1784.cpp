//Date:2018/3/4
//OJ:luogu
//Problem:1784
//Solution:DFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int data[10][10];
bool a[10][10],b[10][10],c[10][10];
const int pos[10][10]={
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
        if(x==9&&y==9) 
        {
            for(int i=1;i<=9;i++)
            {
                for(int j=1;j<=9;j++)
                    cout<<data[i][j]<<' ';
                cout<<endl;
            }
            exit(0);
        }
        if(y==9) 
            dfs(x+1,1); 
        else
            dfs(x,y+1);
    }
    else 
    {
        for(int k=1;k<=9;k++)
        {
            if(a[x][k])continue;
            if(b[y][k])continue;
            if(c[pos[x-1][y-1]][k])continue;
            data[x][y]=k;
            if(x==9&&y==9) 
            {
                for(int i=1;i<=9;i++)
                {
                    for(int j=1;j<=9;j++)
                        cout<<data[i][j]<<' ';
                    cout<<endl;
                }
                exit(0);
            }
            a[x][k]=true;
            b[y][k]=true;
            c[pos[x-1][y-1]][k]=true;
            dfs(y==9?x+1:x,y==9?1:y+1);
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
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
        {
            cin>>data[i][j];
            a[i][data[i][j]]=true;
            b[j][data[i][j]]=true;
            c[pos[i-1][j-1]][data[i][j]]=true;
        }
    dfs(1,1);
    return 0;
}