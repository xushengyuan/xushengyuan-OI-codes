//Date:2018/3/5
//OJ:luogu
//Problem:1026
//Solution:DP
//By:xushengyuan
//f[i][j]表示用前i个字母切分为j段时可获得的最大单词数
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 210
#define MOD 1000007
using namespace std;
int p, _k, s;
int f[MAXN][MAXN], cot[MAXN][MAXN];
int words_hash[10];
string words[10];
char ch[210];
int _hash(string str)
{
    int result = 0;
    for (int i = 0; i < str.length(); i++)
        result = (result * 97 + str[i]) % MOD;
    return result;
}
int dp()
{
    memset(f, 0, sizeof(f));
    for (int k = 1; k <= _k; k++)
        for (int i = 1; i <= p * 20; i++)
            for (int j = k - 1; j < i; j++)
                f[i][k] = max(f[i][k], f[j][k - 1] + cot[j][i - 1]);
    return f[p * 20][_k];
}
int hashs[MAXN][MAXN];
bool vis[MAXN];
void init()
{
    memset(hashs, 0, sizeof(hashs));
    memset(cot, 0, sizeof(cot));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < p * 20; i++)
    {
        int t = 0;
        for (int j = i; j < p * 20; j++)
        {
            t = (t * 97 + ch[j]) % MOD;
            hashs[i][j] = t;
        }
    }
    for (int i = 0; i < p * 20; i++)
    {
        for (int j = i; j < p * 20; j++)
        {
            memset(vis, 0, sizeof(vis));
            for (int k = 0; k < s; k++)
            {
                int len = words[k].length();
                if (len > j - 1 + 1)
                    continue;
                for (int t = i; t <= j - len + 1; t++)
                    if (!vis[t] && hashs[t][t + len - 1] == words_hash[k])
                    {
                        vis[t] = true;
                        cot[i][j]++;
                    }
            }
        }
    }
    return;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> p >> _k;
    int pp = 0;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < 20; j++, pp++)
            cin >> ch[pp];
    cin >> s;
    for (int i = 0; i < s; i++)
        cin >> words[i];
    for (int i = 0; i < s; i++)
        words_hash[i] = _hash(words[i]);
    init();
    cout << dp();
    return 0;
}