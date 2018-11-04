//Date:2018/10/14
//OJ:luogu
//Problem:U41569
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10
using namespace std;
int n;
struct portal
{
    int t, d, c;
} data[MAXN];
int f[MAXN];
vector<int> link[MAXN];
bool cmp(portal a, portal b)
{
    return a.d < b.d;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    int maxt = 0, maxd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].t >> data[i].d >> data[i].c;
        maxt = max(maxt, data[i].t);
        maxd = max(maxd, data[i].d);
    }
    sort(data, data + n, cmp);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
        for (int j = data[i].d + maxt; j >= data[i].t; j--)
            if (j - data[i].t < data[i].d)
            {
                f[j] = max(f[j], f[j - data[i].t] + data[i].c);
                link[j - data[i].t].push_back(j);
            }
    int result = 0;
    for (int i = 0; i <= maxd; i++)
        result = max(result, f[i]);
    cout << result;
    return 0;
}
