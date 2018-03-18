//Date:2018/3/10
//OJ:luogu
//Problem:2233
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MOD 1000
using namespace std;
int f[5][3];
int n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(f,0,sizeof(f));
    cin>>n;
    int p=0,rp;
    f[1][0]=1;
    for(int i=0;i<n;i++)
    {
        rp=p;
        p=(p==0?1:0);
        f[4][p]=f[3][rp]%MOD;
        f[3][p]=(f[2][rp]+f[4][rp])%MOD;
        f[2][p]=(f[1][rp]+f[3][rp])%MOD;
        f[1][p]=(2*f[2][rp])%MOD;
    }
    cout<<(2*f[4][rp])%MOD;
    return 0;
}