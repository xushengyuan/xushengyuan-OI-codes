//Date:2018/11/4
//OJ:luogu
//Problem:4937
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 2050
using namespace std;
int n, f[MAXN];
struct thing
{
    int t, d, c;
} th[200];
vector<int> link[2050];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> th[i].t >> th[i].d >> th[i].c;
    f[0] = 0;
    for (i = 1; i <= n; i++)
        for (j = th.d[i] + th[i].c; j >= th[i].c; j--)
            if (j < th.d[i] + th[i].c && j - th[i].c >= 0 && f[j - th[i].c] + th[i].c * th[i].t > f[j])
            {
                f[j] = f[j - th[i].c] + th[i].c * th[i].t;
                link[j].push_back(i);
            }
    int p = 0, Max = -1;
    for (int i = 2040, i >= 0; i--)
        if (Max < f[i])
        {
            Max = f[i];
            p = i;
        }

    return 0;
}