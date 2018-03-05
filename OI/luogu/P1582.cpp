//Date:2018/2/25
//OJ:luogu
//Problem:1582
//Solution:Math&Bit
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,k;
inline int lowbit(int x)
{
    return x&-x;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>k;
    int result=0;
    while(__builtin_popcount(n) > k)
    {
        result+=lowbit(n);
        n+=lowbit(n);
    }
    cout<<result;
    return 0;
}