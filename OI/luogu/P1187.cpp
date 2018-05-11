//Date:2018/4/14
//OJ:luogu
//Problem:1187
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1010
using namespace std;
int m,n,data[MAXN][MAXN];
int result=0;
int read_char()
{
    char t=getchar();
    while(!isdigit(t))
        t=getchar();
    return t-'0';
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(data,0,sizeof(data));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            data[i][j]=read_char();
            if(data[i][j]!=0)
                result+=2;
        }
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m+1;j++)
        {
            result+=abs(data[i][j]-data[i-1][j]);
            result+=abs(data[i][j]-data[i][j-1]);
        }
    cout<<result;
    return 0;
}