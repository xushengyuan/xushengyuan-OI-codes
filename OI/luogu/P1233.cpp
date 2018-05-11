//Date:2018/4/24
//OJ:luogu
//Problem:1233
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 5010
#define INF 0x7fffffff
using namespace std;
int n;
struct node
{
    int l, w;
} data[MAXN];
int _time[MAXN];
bool cmp(node a, node b)
{
    return a.l > b.l;
}
bool operator<(node a, node b)
{
    return a.w < b.w;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i].l >> data[i].w;
    sort(data, data + n, cmp);
    int ans = 0;
    //bfor(int i=0;i<n;i++)
    //  b  cout<<data[i].l<<' '<<data[i].w<<endl;
    set<node> g;
    for (int i = 0; i < n; i++)
    {
        if (g.empty())
        {
            g.insert(data[i]);
            ans++;
        }
        set<node>::iterator p = g.lower_bound(data[i]);
        if (p != g.end())
            g.erase(p), g.insert(data[i]);
        else
            ans++, g.insert(data[i]);
    }
    cout << ans;
    return 0;
}