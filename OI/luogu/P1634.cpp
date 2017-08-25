//Date:2017/8/11
//OJ:luogu
//Problem:1634
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    long long x,n,i,sum=1;
    cin >>x>>n;
    for(i=0;i<n;i++)
        sum*=x+1;
    cout <<sum;
    return 0;
}