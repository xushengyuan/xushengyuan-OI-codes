//Date:2018/10/23
//OJ:luogu
//Problem:4932
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#include <cstdlib>
#define _DEBUG
using namespace std;
long long n,a,b,c,d,x0;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>a>>b>>c>>d>>x0;
    long long cot1=0,cot2=0;
    long long xi;
    for(register int i=1;i<=n;i++)
    {
        xi = ((x0 * x0) % d * a % d + x0 * b % d + c) % d;
        if (__builtin_popcount(xi) & 1)
            cot1++;
        else
            cot2++;
        x0=xi;
    }
    // cot1++;
    cout<<cot1*cot2;
    return 0;
}
