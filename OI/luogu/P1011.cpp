//Date:2018/7/18
//OJ:luogu
//Problem:1011
//Solution:math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 25
using namespace std;
int a, n, m, x;
int f[MAXN];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> a >> n >> m >> x;
    if (x == 1)
    {
        cout << a;
        return 0;
    }
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < MAXN; i++)
        f[i] = f[i - 2] + f[i - 1];
    int t = (m - f[n - 3] * a - a) / (f[n - 2] - 1);
    cout << t * (f[x - 1] - 1) + a * (f[x - 2] + 1);
    return 0;
}
