//Date:2018/9/16
//OJ:luogu
//Problem:2261
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
using namespace std;
ll n,k;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>k;
    ll r,tmp,result=n*k;
    for(ll i=1;i<=n;i=r+1)
    {
        tmp=k/i;
        if(tmp!=0)
            r=min(k/tmp,n);
        else
            r=n;
        result-=tmp*(r-i+1)*(r+i)/2;
    }
    cout<<result;
    return 0;
}