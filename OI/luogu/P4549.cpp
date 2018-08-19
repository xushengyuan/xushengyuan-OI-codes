//Date:2018/8/17
//OJ:luogu
//Problem:4549
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,result=0,t;
int gcd(int x,int y)
{
    if(y!=0)
        return gcd(y,x%y);
    else
        return x;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        result=gcd(result,abs(t));
    }
    cout<<result;
    return 0;
}