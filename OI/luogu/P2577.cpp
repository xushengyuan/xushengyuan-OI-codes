//Date:2018/7/5
//OJ:luogu
//Problem:P2577
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 210
using namespace std;
int n;
int f[MAXN][MAXN*MAXN], pre[MAXN] = {0};
struct person
{
    int a, b;
} data[MAXN];
bool cmp(person a, person b)
{
    return a.b > b.b;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> data[i].a >> data[i].b;
    sort(data + 1, data + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + data[i].a;
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= pre[i]; j++)
        {
            if (j >= data[i].a)
                f[i][j] = min(f[i][j], max(f[i - 1][j - data[i].a], j + data[i].b));
            f[i][j] = min(f[i][j], max(f[i - 1][j], pre[i] - j + data[i].b));
        }
    int _min = 2333333, ans = -1;
    for (int j = 0; j <= pre[n]; j++)
        _min = min(_min, f[n][j]);
    cout << _min;
    return 0;
}
