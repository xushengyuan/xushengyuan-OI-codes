//Date:2018/8/20
//OJ:luogu
//Problem:3740
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10000000
using namespace std;
int n, m;
int u[MAXN], v[MAXN];
bool vis[MAXN];
int ans = 0;
inline int read_int()
{
    int result = 0;
    char t = getchar();
    while (!isdigit(t))
        t = getchar();
    while (isdigit(t))
    {
        result = result * 10 + t - '0';
        t = getchar();
    }
    return result;
}
void f(int p, int up, int vp,int c)
{
    if (vis[c])
        return;
    while (p <= m && (vp <= u[p] || up >= v[p]))
        p++;
    if (p == m + 1)
    {
        ans++;
        vis[c] = true;
    }
    if (up < u[p] && vp > u[p])
        f(p + 1, up, u[p],c);
    if (vp > v[p] && up < v[p])
        f(p + 1, v[p], vp,c);
    return;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(vis, 0, sizeof(vis));
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        u[i] = read_int(), v[i] = read_int()+1;
    for (int i = m-1; i >= 1; i--)
        f(i+1, u[i], v[i],i) ;
    cout<<ans+1;
    return 0;
}