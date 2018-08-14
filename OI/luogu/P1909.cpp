//Date:2018/8/6
//OJ:luogu
//Problem:1909
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
int n;
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    double ans=0x7fffffff;
    for(int i=0;i<3;i++)
    {
        int a,b;
        cin>>a>>b;
        ans=min(ans,ceil(n*1.0/a)*b);
    }
    cout<<(int)ans;
    return 0;
}