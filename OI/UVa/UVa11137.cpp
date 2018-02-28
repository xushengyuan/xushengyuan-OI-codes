//Date:2018/2/27
//OJ:UVa
//Problem:11137
//Solution:DP+
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define MAXN 10000
using namespace std;
long long f[30][MAXN+10];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(int i=1;i<=25;i++)
        for(int j=0;j<=MAXN;j++)
            for(int k=0;(k*i*i*i+j)<=MAXN;k++)
                f[i][j+k*i*i*i]+=f[i-1][j];
    while((scanf("%d",&t))>0)
        cout<<f[25][t]<<endl;
    return 0;
}