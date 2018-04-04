//Date:2018/3/31
//OJ:luogu
//Problem:3382
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 20
#define EPS 1E-7
#define ld long double
using namespace std;
int n;
ld l, r;
ld data[MAXN];
ld f(ld x)
{
    ld result = 0, tmp = 1;
    for (int i = 0; i <= n; i++)
    {
        result += tmp * data[i];
        tmp *= x;
    }
    return result;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> l >> r;
    for (int i = n; i >=0; i--)
        cin >> data[i];
    ld pl = l, pr = r;
    while (EPS <= fabs(pr - pl))
    {
        ld mid = (pl + pr) / 2;
        ld f1 = f(mid - EPS), f2 = f(mid + EPS);
        if (f1 < f2)
            pl = mid;
        else
            pr = mid;
    }
    printf("%.5lf",(double)pl);
    return 0;
}
