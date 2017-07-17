/*
    problem : Luogu 1077
    solution : DP
    
    评测结果：Accepted 
    得分：　　100
    提交时间：2017-06-30 20:29
    耗时：424ms
    内存：12042kb
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

int n, m;
int a[N];
int f[N][N];

int work()
{
    f[0][0] = 1;

    for(int i = 1; i <= n; ++ i)
        for(int j = 0; j <= m; ++ j)
            for(int k = 0; k <= j && k <= a[i]; ++ k)
                f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;

    return f[n][m];
}


int main()
{

    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    cout << work() << endl;

    return 0;
}