//Date:2017/8/12
//OJ:luogu
//Problem:1876
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    cin >>n;
    for(int i=1;i<=sqrt(n);i++)
        cout <<i*i<<' ';
    return 0;
}