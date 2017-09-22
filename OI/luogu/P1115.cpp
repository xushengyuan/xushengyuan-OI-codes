//Date:2017/9/10
//OJ:luogu
//Problem:1115
//Solution:DP 
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 200100
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,t;
    cin >>n;
    int sum=0,ans=-0x7fffffff;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        sum+=t;
        ans=max(ans,sum);
        sum=sum<0?0:sum;
    }   
    cout <<ans;
    return 0;
}