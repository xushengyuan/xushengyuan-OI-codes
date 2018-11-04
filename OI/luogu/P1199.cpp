//Date:2018/10/26
//OJ:luogu
//Problem:1199
//Solution:贪心
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 510
#define _DEBUG
using namespace std;
int n, ans;
int data[MAXN][MAXN];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cin >> data[i][j];
            data[j][i] = data[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        sort(data[i], data[i] + n);
    for (int i = 0; i < n; i++)
        ans=max(ans,data[i][n-2]);
    cout<<1<<endl<<ans;
    return 0;
}