//Date:2018/8/16
//OJ:luogu
//Problem:2563
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 200
#define PRIME_N 46
using namespace std;
int n;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
               101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
int f[MAXN];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < PRIME_N; i++)
        for (int j = prime[i]; j <= MAXN; j++)
            f[j] = f[j] + f[j - prime[i]];
    while (cin >> n)
        cout << f[n] << endl;
    return 0;
}