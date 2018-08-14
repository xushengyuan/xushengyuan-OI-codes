//Date:2018/8/7
//OJ:luogu
//Problem:1220
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 50
using namespace std;
int n,c;
int f[MAXN][MAXN][2],datap[MAXN],datal[MAXN],pre[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>datal[i]>>datap[i];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=datap[i];
        pre[i]=sum;
    }
    memset(f,0x3f,sizeof(f));
    f[c][c][0]=f[c][c][1]=0;
    for(int j=c;j<=n;j++)
        for(int i=j-1;i>0;i--)
            f[i][j][1]=min(
                (datal[j]-datal[j-1])*(pre[n]-pre[j-1]+pre[i-1])+f[i][j-1][1],
                (datal[j]-datal[i])*(pre[n]-pre[j-1]+pre[i-1])+f[i][j-1][0]),
            f[i][j][0]=min(
                (datal[j]-datal[i])*(pre[n]-pre[j]+pre[i])+f[i+1][j][1],
                (datal[i+1]-datal[i])*(pre[n]-pre[j]+pre[i])+f[i+1][j][0]);
    cout<<min(f[1][n][0],f[1][n][1]);
    return 0;
}