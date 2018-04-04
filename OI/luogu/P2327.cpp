//Date:1028/3/29
//OJ:luogu
//Problem:2327
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10010
using namespace std;
int n, ans = 0;
bool flag = false;
int data[MAXN];
short f[MAXN];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    
    memset(f, 0, sizeof(f));
    f[0] = 1;
    flag = false;
    for (int i = 1; i <= n; i++)
    {
        int t = data[i - 1] - f[i - 1] - f[i - 2];
        if (t == 0 || t == 1)
            f[i] = t;
        else
        {
            flag = true;
            break;
        }
    }
    if (!flag && f[n] == 0)
        ans++;

    memset(f, 0, sizeof(f));
    f[0] = 0;
    flag = false;
    for (int i = 1; i <= n; i++)
    {
        int t = data[i - 1] - f[i - 1] - f[i - 2];
        if (t == 0 || t == 1)
            f[i] = t;
        else
        {
            flag = true;
            break;
        }
    }
    if (!flag && f[n] == 0)
        ans++;
    cout << ans;
}
