//Date:2018/2/18
//OJ:luogu
//Problem:1216
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10
using namespace std;
int n;
int data[MAXN][MAXN],f[MAXN][MAXN];
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(f,0,sizeof(f));
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<i+1;j++)
        {
            data[i][j]=read_int();
            f[i][j]=data[i][j];
        }

    for(int i=n-1;i>=0;i--)
        for(int j=i;j>=0;j--)
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+data[i][j];
    cout<<f[0][0];
    return 0;
}