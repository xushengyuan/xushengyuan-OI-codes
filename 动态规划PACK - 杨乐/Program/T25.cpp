/*
    problem : Luogu 1040
    solution : DP
    
    评测结果：Accepted 
    得分：　　100
    提交时间：2017-06-30 21:45
    耗时：0ms
    内存：12050kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 105;
const int MOD = 1000007;

int n;
int a[N];
LL f[N][N], g[N][N];

int work()
{
    for(int i = 1; i <= n; ++ i) f[i][i] = a[i], g[i][i] = i;
    for(int i = 0; i <= n; ++ i) f[i+1][i] = 1;

    for(int k = 1; k < n; ++ k)
        for(int i = 1; i + k <= n; ++ i)
        {
            int j = i + k;
            for(int l = i; l <= j; ++ l)
            {
                LL t = f[i][l-1] * f[l+1][j] + a[l];
                if(t > f[i][j]) f[i][j] = t, g[i][j] = l;
            }
        }

    return f[1][n];
}

void dfs(int x, int y)
{
    if(x > y) return;

    int l = g[x][y];
    cout << l << " ";
    dfs(x, l-1), dfs(l+1, y);
}

int main()
{

    cin >> n;
    
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    
    cout << work() << endl;
    
    dfs(1, n);

    return 0;
}