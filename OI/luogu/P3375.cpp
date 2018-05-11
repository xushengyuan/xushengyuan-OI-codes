//Date:2018/4/5
//OJ:luogu
//Problem:3375
//Solution:KMP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 2000010
using namespace std;
char text[MAXN], pat[MAXN];
int n, m, f[MAXN];
void init_kmp()
{
    f[0] = 0;
    f[1] = 0;
    for (int i = 1; i < m; i++)
    {
        int t = f[i];
        while (t != 0 && pat[i] != pat[t])
            t = f[t];
        if (pat[i] == pat[t])
            f[i + 1] = t + 1;
        else
            f[i + 1] = 0;
    }
    return;
}
void kmp()
{
    init_kmp();
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        while (t != 0 && pat[t] != text[i])
            t = f[t];
        if (pat[t] == text[i])
            t++;
        if (t == m)
            cout << i - m + 2 << endl;
    }
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s", text, pat);
    n = strlen(text);
    m = strlen(pat);
    kmp();
    for (int i = 1; i <= m; i++)
        cout << f[i] << ' ';
    cout << endl;
    return 0;
}