//Date:2018/8/14
//OJ:luogu
//Problem:4781
//Solution:Lagrange
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 2010
#define MOD 998244353
using namespace std;
long long  n, x, data[MAXN][2];
long long qpow(long long x, long long y)
{
    long long result = 1;
    while (y != 0)
    {
        if (y & 1)
            result = result * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return result;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> data[i][0] >> data[i][1];
    long long  ans = 0;
    for (int k = 0; k < n; k++)
    {
        long long t1 = 1, t2 = 1;
        for (int j = 0; j < n; j++)
            if (j != k)
            {
                t1 = (t1 * (x - data[j][0])) % MOD;
                t2 = (t2 * (data[k][0] - data[j][0])) % MOD;
            }
        ans = (ans + data[k][1] * t1 % MOD * qpow(t2, MOD - 2) % MOD) % MOD;
    }
    cout << (ans + MOD) % MOD;
    return 0;
}