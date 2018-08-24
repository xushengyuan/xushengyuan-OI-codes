//Date:2018/8/21
//OJ:luogu
//Problem:2280
//Solution:pre
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 5010
#define N 10
#define _DEBUG
using namespace std;
int f[MAXN][MAXN];
int n, r;
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
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> r;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
    {
        int x = read_int() + 1, y = read_int() + 1, w = read_int();
        f[x][y] = w;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    int Max = 0;
    // for (int i = r; i < N; i++)
    // {
    //     for (int j = r; j < N; j++)
    //         cout << f[i][j] << ' ';
    //     cout << endl;
    // }
    for (int i = 0; i <= N - r; i++)
        for (int j = 0; j <= N - r; j++)
            Max = max(Max, f[i + r][j + r] - f[i + r][j] - f[i][j + r] + f[i][j]);
    cout << Max;
    return 0;
}