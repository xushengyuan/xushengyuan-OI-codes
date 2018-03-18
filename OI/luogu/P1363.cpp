//Date:2018/3/16
//OJ:luogu
//Problem:1363
//Solution:DFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1510
using namespace std;
bool data[MAXN * 3][MAXN * 3], vis[MAXN * 3][MAXN * 3], v[MAXN * 3][MAXN * 3],exit_flag = false;
int m, n, pm, pn, sx, sy;
const int _move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
inline bool isInRange(int x, int y)
{
    return x >= 0 && y >= 0 && x < pn && y < pm;
}
inline void read_map(int x, int y)
{
    int t = getchar();
    while (t != '.' && t != '#' && t != 'S')
        t = getchar();
    if (t == 'S')
    {
        data[x][y] = true;
        sx = x + n, sy = y + m;
    }
    else if (t == '.')
        data[x][y] = true;
    else
        data[x][y] = false;
    const int _m[8][2] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}, {2, 1}, {0, 2}, {1, 2}, {2, 2}};
    for (int j = 0; j < 8; j++)
        data[x + _m[j][0] * n][y + _m[j][1] * m] = data[x][y];
    return;
}
inline void read_data()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            read_map(i, j);
}
void dfs(int x, int y)
{
    if (exit_flag)
        return;
    if (v[(x+1) % n][(y+1) % m] && ((x < n || x >= 2 * n) || (y < m || y >= 2 * m)))
    {
        exit_flag = true;
        return;
    }
#ifdef _DEBUG
    cout << x << ' ' << y << endl;
    for (int i = 0; i < pn; i++)
    {
        for (int j = 0; j < pm; j++)
            cout << vis[i][j];
        cout << endl;
    }
#endif
    for (int k = 0; k < 4; k++)
    {
        int tx = x + _move[k][0], ty = y + _move[k][1];
        if ((tx >= 0 && ty >= 0 && tx < pn && ty < pm) && data[tx][ty] && !vis[tx][ty])
        {
            vis[tx][ty] = true;
            v[(tx)%n][(ty)%m]=true;
            dfs(tx, ty);
        }
    }
    return;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n >> m)
    {
        pn = n * 3, pm = m * 3;
        read_data();
        exit_flag=false;
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(vis));
#ifdef _DEBUG
    for (int i = 0; i < pn; i++)
    {
        for (int j = 0; j < pm; j++)
            cout << data[i][j];
        cout << endl;
    }
#endif
        vis[sx][sy]=true;
        v[sx%n][sy%m]=true;
        dfs(sx, sy);
        if (exit_flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}