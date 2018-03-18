//Date:2018/3/18
//OJ:luogu
//Problem:2439
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10010
using namespace std;
int f[MAXN], pk[MAXN * 3];
int n;
struct speech
{
    int p, k;
} data[MAXN];
int read_int()
{
    int result = 0;
    char t;
    t = getchar();
    while (!isdigit(t))
        t = getchar();
    while (isdigit(t))
    {
        result = result * 10 + t - '0';
        t = getchar();
    }
    return result;
}
bool cmp(speech a, speech b)
{
    return a.k < b.k;
}
bool cmp1(speech a, speech b)
{
    return a.p < b.p;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(f, 0, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; i++)
        data[i].p = read_int(), data[i].k = read_int();
    sort(data, data + n, cmp);
#ifdef _DEBUG
    for (int i = 0; i < n; i++)
        cout << data[i].p << ' ' << data[i].k << endl;
#endif
    for (int i = 0; i < data[0].k; i++)
        pk[i] = -1;
    for (int i = 0; i < n - 1; i++)
        for (int k = data[i].k; k < data[i + 1].k; k++)
            pk[k] = i;
    //sort(data,data+n,cmp1);
    for (int i = 0; i < n; i++)
    {
        f[i] = (data[i].k - data[i].p);
        for (int j = pk[data[i].p]; j >= 0; j--)
        {
            f[i] = max(f[i], f[j] + (data[i].k - data[i].p));
#ifdef _DEBUG
            for (int k = 0; k < n; k++)
                cout << f[k] << ' ';
            cout << endl;
#endif
        }
    }
#ifdef _DEBUG
    for (int i = 0; i < n; i++)
        cout << f[i] << ' ';
    cout << endl;
#endif
    int _max = -1;
    for (int i = 0; i < n; i++)
        _max = max(_max, f[i]);
    cout << _max;
    return 0;
}