//Date:2018/4/11
//OJ:luogu
//Problem:1736
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 2510
using namespace std;
int n,m;
bool data[MAXN][MAXN];
int f1[MAXN][MAXN],f2[MAXN][MAXN],f0[MAXN][MAXN];
int _max=0;
int read_int()
{
    char t;
    int result=0;
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int t=read_int();
            if(t==1)
                data[i][j]=true;
            else
                data[i][j]=false;
        }
    memset(f0,0,sizeof(f0));
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(data[i][j]==false)
            {
                f1[i][j]=f1[i-1][j]+1;
                f2[i][j]=f2[i][j-1]+1;
            }
            else
            {
                f0[i][j]=min(f0[i-1][j-1],min(f1[i-1][j],f2[i][j-1]))+1;
                _max=max(_max,f0[i][j]);
            }
    memset(f0,0,sizeof(f0));
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            if(data[i][j]==false)
            {
                f1[i][j]=f1[i-1][j]+1;
                f2[i][j]=f2[i][j+1]+1;
            }
            else
            {
                f0[i][j]=min(f0[i-1][j+1],min(f1[i-1][j],f2[i][j+1]))+1;
                _max=max(_max,f0[i][j]);
            }
    cout<<_max<<endl;
    return 0;
}