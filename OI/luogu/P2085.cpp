//Date:2018/6/11
//OJ:luogu
//Problem:2085
//Solution:Math Queue
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define MAXN 10000
using namespace std;
int n, m;
int a[MAXN], b[MAXN], c[MAXN];
struct v
{
    int x, f, i;
};
bool operator>(v a, v b)
{
    return a.f > b.f;
}
inline int f(int i, int x)
{
    return a[i] * x * x + b[i] * x + c[i];
}
priority_queue<v, vector<v>, greater<v>> Q;
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        v t = {1, f(i, 1), i};
        Q.push(t);
    }
    for (int i = 0; i < m; i++)
    {
        v p = Q.top();
        cout << p.f << ' ';
        Q.pop();
        v t = {p.x + 1, f(p.i, p.x + 1), p.i};
        Q.push(t);
    }
    return 0;
}