//Date:2018/11/4
//OJ:luogu
//Problem:4936
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MOD 1000000007
using namespace std;
int n;
long long qpow(long long n,int k)
{
    if(k==0)
        return 1;
    else if(k&1==1)
        return qpow(n*n%MOD,k/2)*n%MOD;
    return qpow(n*n%MOD,k/2)%MOD;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    cout<<(n-2)*qpow(2,n-1)%MOD+1;
    return 0;
}