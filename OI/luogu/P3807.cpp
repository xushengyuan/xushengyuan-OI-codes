//Date:2018
//OJ:luogu
//Problem:3807
//Solution:Math-Lucas
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 100010
using namespace std;
int T, n, m, p;
long long data[MAXN];
ll pow(ll y,int z,int p){
    y%=p;ll ans=1;
    for(int i=z;i;i>>=1,y=y*y%p)if(i&1)ans=ans*y%p;
    return ans;
}
long long qpow(int x, int y, int p)
{
    x %= p;
    long long result = 1;
    for (int i = y; i > 0; i >>= 1, x = x * x % p)
        if (i & 1)
            result = result * x % p;
    return result;
}

long long C(long long n, long long m, long long p)
{
    if (n < m)
        return 0;
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> T;
    while (T--)
    {
        data[0] = 1;
        cin >> n >> m >> p;
        for (int i = 1; i <= p; i++)
            data[i] = (data[i - 1] * i) % p;
        cout << lucas(n + m, n, p) << endl;
    }
    return 0;
}