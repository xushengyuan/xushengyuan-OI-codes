//Date:2018/4/10
//OJ:luogu
//Problem:1865
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1000010
using namespace std;
int n, m;
bool is_p[MAXN];
int pref[MAXN];
int primes, prime[MAXN / 10];
void init(int nn)
{
    memset(is_p, 0, sizeof(is_p));
    primes = 0;
    is_p[0] = is_p[1] = true;
    for (int i = 2; i <= nn; ++i)
    {
        if (!is_p[i])
        {
            prime[++primes] = i;
        }
        for (int j = 1; j <= primes && i * prime[j] <= nn; ++j)
        {
            is_p[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
    pref[0] = 0;
    for (int i = 1; i <= nn; i++)
        if (!is_p[i])
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = pref[i - 1];
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    init(m);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (r < 1 || r > m || l < 1 || l > m)
            cout << "Crossing the line" << endl;
        else
            cout << pref[r] - pref[l - 1] << endl;
    }
    return 0;
}