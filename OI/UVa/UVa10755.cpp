//Date:2018/8/15
//OJ:UVa
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 22
#define ll long long
#define INF 0x7fffffffffffffff
using namespace std;
int T, a, b, c;
ll data[MAXN][MAXN][MAXN],
    pre[MAXN][MAXN][MAXN];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        memset(pre, 0, sizeof(data));
        for (int x = 0; x < a; x++)
            for (int y = 0; y < b; y++)
                for (int z = 0; z < c; z++)
                {
                    cin >> data[x][y][z];
                    if (x == 0 && y == 0 && z == 0)
                        pre[x][y][z] = data[x][y][z];
                }
        //pre
        for (int x = 0; x < a; x++)
            for (int y = 0; y < b; y++)
                for (int z = 0; z < c; z++)
                    if(x!=0 || y!=0 || z!=0)
                        pre[x][y][z] =
                        data[x][y][z] + pre[x - 1][y][z] + pre[x][y - 1][z] + pre[x][y][z - 1] - pre[x - 1][y - 1][z] - pre[x - 1][y][z - 1] - pre[x][y - 1][z - 1] + pre[x - 1][y - 1][z - 1];
        ll ans = -INF;
        for (int x1 = 0; x1 < a; x1++)
            for (int x2 = x1; x2 >= 0; x2--)
                for (int y1 = 0; y1 < b; y1++)
                    for (int y2 = y1; y2 >= 0; y2--)
                    {
                        ll Min = 0;
                        for (int z = 0; z < c; z++)
                        {
                            long long t = pre[x1][y1][z] - pre[x1][y2-1][z] - pre[x2-1][y1][z] + pre[x2-1][y2-1][z];
                            ans = max(ans, t - Min);
                            Min = min(Min, t);
                        }
                    }
        cout << ans<<endl;
        if(T!=0)
            cout<<endl;
    }
    return 0;
}