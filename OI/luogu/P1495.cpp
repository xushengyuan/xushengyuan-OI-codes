//Date:2018/10/23
//OJ:luogu
//Problem:1495
//Solution:CRT
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 12
using namespace std;
int k;
int a[MAXN], b[MAXN];
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long temp = x;
    x = y, y = temp - a / b * y;
    return d;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >>k;
    for (int i = 0; i < k; i++)
        cin >> a[i] >> b[i];
    long long x, y, ans = 0, m, n = 1;
    for (long long i = 0; i < k; i++)
        n *= a[i];
    for (long long i = 0; i < k; i++)
    {
        m = n / a[i];
        exgcd(a[i], m, x, y);
        ans = (ans + y * m * b[i]) % n;
    }
    cout << (ans+ n) % n;
    return 0;
}