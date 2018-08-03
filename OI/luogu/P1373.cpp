//Date:2018/8/3
//OJ:kuogu
//Problem:1373
//Solution:DP   
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 805
#define MOD 1000000007
using namespace std;
int n,m,k;
long long ans=0;
int f[MAXN][MAXN][20][2];
int data[MAXN][MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(f,0,sizeof(f));
    cin>>n>>m>>k;
    k++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>data[i][j];
            //data[i][j]%=k;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j][data[i][j]%k][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int kk=0;kk<k;kk++)
            {
                f[i][j][kk][0]=(
                    f[i][j][kk][0]+
                    f[i-1][j][(k+kk-data[i][j])%k][1]+
                    f[i][j-1][(k+kk-data[i][j])%k][1])%MOD;
                f[i][j][kk][1]=(
                    f[i][j][kk][1]+
                    f[i-1][j][(k+kk+data[i][j])%k][0]+
                    f[i][j-1][(k+kk+data[i][j])%k][0])%MOD;
            }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //cout<<f[i][j][0][1]<<' ';
            ans=(ans+f[i][j][0][1])%MOD;
        }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}