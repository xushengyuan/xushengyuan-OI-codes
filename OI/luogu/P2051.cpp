//Date:2018/8/17
//OJ:luogu
//Problem:2051
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
#define MOD 9999973
using namespace std;
int n, m;
long long f[MAXN][MAXN][MAXN];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            f[0][i][j] = 0;
    f[0][0][0] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 0; i <= m; i++)         //有一个的列数
            for (int j = 0; i + j <= m; j++) //有两个的列数
            {
                int l = m - i - j;
                //一个都不放
                f[k][i][j] = (f[k][i][j] + f[k - 1][i][j]) % MOD;
                //放一个 放在没有棋子的一列
                if (i > 0 && l + 1 >= 1)
                    f[k][i][j] = (f[k][i][j] + f[k - 1][i - 1][j] * (l + 1)) % MOD;
                //放一个 放在有一个棋子的一列
                if (j > 0)
                    f[k][i][j] = (f[k][i][j] + f[k - 1][i + 1][j - 1] * (i + 1)) % MOD;
                //放两个 放在没有棋子的两列
                if (i > 1 && l + 2 >= 2)
                    f[k][i][j] = (f[k][i][j] + f[k - 1][i - 2][j] * (l + 2) * (l + 2 - 1) / 2) % MOD;
                //放两个 放在有一个棋子的两列
                if (j > 1)
                    f[k][i][j] = (f[k][i][j] + f[k - 1][i + 2][j - 2] * (i + 2) * (i + 2 - 1) / 2) % MOD;
                //放两个 放一个在有一个棋子的列一个在没有棋子的列
                if (i > 0 && j > 0 && l + 2 >= 1)
                    f[k][i][j] = (f[k][i][j] + f[k - 1][i][j - 1] * (l + 1) * (i )) % MOD;
            }
    long long ans = 0;
    /*for (int i = 0; i <= m; ++i) // 有1个棋子的列
    {
        for (int j = 0; j <= m; ++j)
        { // 2个棋子的列
            cout << f[n][i][j] << ' ';
        }
        cout << endl;
    }*/
    for (int i = 0; i <= m; i++)
        for (int j = 0; i + j <= m; j++)
            ans = (ans + f[n][i][j]) % MOD;
    cout << ans;
    return 0;
}