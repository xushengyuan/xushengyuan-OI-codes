//Date:2018/8/18
//OJ:luogu
//Problem:2613
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MOD 19260817
using namespace std;
long long a,b;
int read_int()
{
    int result=0,flag=1;
    char t;
    t=getchar();
    while(!isdigit(t))
    {
        if(t='-')
            flag=-1;
        t=getchar();
    }
    while(isdigit(t))
    {
        result=(result*10%MOD+(t-'0'))%MOD;
        t=getchar();
    }
    return flag*result;
}
long long qpow(long long x, long long y, int p)
{
    x%=p;
    long long result = 1;
    for (int i = y; i > 0; i >>= 1, x = x * x % p)
        if (i & 1)
            result = result * x % p;
    return result;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    a=read_int(),b=read_int();

    if(b==0)
    {
        cout<<"Angry!";
        return 0;
    }
    long long t=qpow(b,MOD-2,MOD);
    cout<<((a*t)%MOD+MOD)%MOD;
    return 0;
}