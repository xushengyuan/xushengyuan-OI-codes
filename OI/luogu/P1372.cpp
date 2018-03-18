//Date:2018/3/7
//OJ:luogu
//Problem:1372
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,k;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>k;   
    cout<<n/k;
    return 0;
}