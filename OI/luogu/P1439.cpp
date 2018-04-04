//Date:2018/3/19
//OJ:luogu
//Problem:1439
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 100010
using namespace std;
int n, f[MAXN], a[MAXN], b[MAXN], m[MAXN];
int read_int()
{
    int result = 0;
    char t;
    t = getchar();
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = read_int();
        m[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
        b[i] = read_int();
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int left = 0, mid, right = length;
        if (m[b[i]] < f[length])
        {
            while (left < right)
            {
                mid = (left + right) / 2;
                if (f[mid] > m[b[i]])
                    right = mid;
                else
                    left = mid + 1;
            }
            f[left] = min(f[left], m[b[i]]);
        }
        else
        {
            length++;
            f[length] = m[b[i]];
        }
    }
    cout << length;
    return 0;
}