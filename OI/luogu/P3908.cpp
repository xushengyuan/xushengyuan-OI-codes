//Date:2018/10/26
//OJ:luogu
//Problem:39108
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
long long n,ans;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    if(n%2==0)
    {
        n++;
        ans=n;
    }
    if (((n + 1) / 2)%2!=0)
        ans^=1;
    cout<<ans;
    return 0;
}