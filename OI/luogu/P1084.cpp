//Date:2018/10/21
//OJ:luogu
//Problem:1084
//Solution:二分答案 LCA 倍增
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 500010
using namespace std;
int n, m;
int read_int()
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
vector<pair<int, int>> g[MAXN];
int f[MAXN][21], dis[MAXN][21];
void dfs_init(int u)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i].first;
        if (v != f[u][0])
        {
            f[v][0] = u;
            dis[MAXN][0] = g[u][i].second;
            dfs_init(v);
        }
    }
    return;
}
void init()
{
    for (int i = 1; i < 21; i++)
        for (int j = 1; j <= n; j++)
        {
            dis[j][i] = dis[dis[j][i - 1]][i - 1] + dis[j][i - 1];
            f[j][i] = f[f[j][i - 1]][j];
        }
}
vector<int> data;
vector<pair<int, int>> toTop;
vector<pair<int, int>> toRoot;
int vis[MAXN];
bool dfs_check(int p)
{
    bool flag=true,isLeaf=true;
    if(vis[p])
        return true;
    for(int i=0;i<g[p].size();i++)
    {
        int v=g[p][i].first;
        if(v!=f[p][0])
        {
            isLeaf=false;
            if(!dfs_check(v))
                flag=false;
        }
    }
    if(isLeaf)
        return false;
    else
        return flag;
}
bool judge(int t)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++)
    {
        int ltime = t;
        int p = data[i];
        for (int j = 20; j >= 0 && f[p][0] != 1; j--)
            if (f[p][j] != 0 && dis[p][j] <= ltime)
            {
                p = f[p][j];
                ltime -= dis[p][j];
            }
        if (f[p][0] == 1)
            toTop.push_back({p,ltime});
        else
            vis[p] = true;
    }
    for(int i=0;i<g[1].size();i++)
    {
        int v=g[1][i].first;
        if(!dfs_check(v))
            toRoot.push_back({v,g[1][i].second});
    }
    
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    int sumw = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u = read_int(), v = read_int(), w = read_int();
        g[v].push_back(v, w);
        g[u].push_back(u, w);
        sumw += w;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
        data.push_back(read_int());
    memset(f, 0, sizeof(f));
    memset(dis, 0, sizeof(dis));
    dfs_init(1);
    init();
    int l = 0, r = sumw;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (judge(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << mid;
    return 0;
}