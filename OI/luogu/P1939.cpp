//Date: 2018/10/5
//OJ:luogu
//Problem:1939
//Solution: Matrix
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 4 
#define MOD 1000000007
#define LL long long
using namespace std;
struct M
{
    int n;
    LL data[MAXN][MAXN];
}mat;
M operator *(M x,M y)
{
    M z;
    z.n=x.n;
    for(int i=0;i<x.n;i++)
        for(int j=0;j<x.n;j++)
        {
            z.data[i][j]=0;
            for(int k=0;k<x.n;k++)
                z.data[i][j]=(z.data[i][j]+x.data[i][k]*y.data[k][j]%MOD)%MOD;
        }
    return z;
}
M qpow(M x, int y)
{
    M result =x;
    while (y > 0)
    {
        if (y & 1)
            result = result * x ;
        x = x * x ;
        y >>= 1;
    }
    return result;
}
int T,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    M init;
    memset(init.data,0,sizeof(init.data));
    init.n=3;
    init.data[0][0]=1;
    init.data[2][0]=1;
    init.data[0][1]=1;
    init.data[1][2]=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        M ans=qpow(init,n-2);
        cout<<ans.data[0][0]<<endl;
    }
    return 0;
}