//Date:2018/3/6
//OJ:luogu
//Problem:1134
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    long long ans=1;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        ans*=i;
        while(ans%10==0)
            ans/=10;
        ans%=1000000000;
    }
    cout<<ans%10;
    return 0;
}