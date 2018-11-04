//Date:2018/9/26
//OJ:luogu
//Problem:1641
//Solution:C
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,m;
long long data[2000010];
// long long qpow(int x, int y, int p)
// {
//     // x %= p;
//     long long result = 1;
//     for (int i = y; i > 0; i >>= 1, x = x * x % p)
//         if (i & 1)
//             result = result * x % p;
//     return result;
// }
long long qpow(long long x, long long y,int p)
{
    long long result = 1;
    while (y != 0)
    {
        if (y & 1)
            result = result * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return result;
}
long long C(long long n, long long m, long long p)
{
    return ((data[n] * qpow(data[m], p - 2, p) )% p * qpow(data[n - m], p - 2, p)) % p;
}
long long lucas(long long n, long long m, long long p)
{
    if (m == 0)
        return 1;
    else
        return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    int p=20100403;
    data[0] = 1;
    for (int i = 1; i <= n+m; i++)
        data[i] = (data[i - 1] * i) % p;
    cout<<(lucas(n+m,m,p)-lucas(n+m,m-1,p)+p)%p;
    return 0;
}