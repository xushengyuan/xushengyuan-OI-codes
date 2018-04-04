//Date:2018/3/16
//OJ:luogu
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define MAXN 40100
using namespace std;
int n, result[MAXN];
long long ans = 0;
struct seg
{
    int a, b, h;
} data[MAXN];
bool cmp(seg a, seg b)
{
    if (a.a != b.a)
        return a.a < b.a;
    else
        return a.h < b.h;
}
vector<int> t, tt;
vector<seg *> S;
int main()
{
    //#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //#endif
    memset(result, 0, sizeof(result));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, h;
        cin >> a >> b >> h;
        data[i] = {a, b, h};
        tt.push_back(a);
        tt.push_back(b);
    }
    sort(data, data + n, cmp);
    sort(tt.begin(), tt.end(), less<int>());
    int p = tt[0], len = tt.size();
    for (int i = 1; i < len; i++)
        if (tt[i] == p)
            tt[i] = -1;
        else
            p = tt[i];
    for (int i = 0; i < len; i++)
        if (tt[i] != -1)
            t.push_back(tt[i]);
    vector<seg *> links[2 * MAXN];
    len = t.size();
#ifdef _DEBUG
    // for (int i = 0; i < len; i++)
    //     cout << t[i] << ' ';
    // cout << endl;
    for (int i = 0; i < 20; i++)
        cout << data[i].a << ' ' << data[i].b << endl;
#endif
    for (int i = 0; i < n; i++)
    {
#ifdef _DEBUG
        cout << lower_bound(t.begin(), t.end(), data[i].b) - t.begin() << endl;
#endif
        links[lower_bound(t.begin(), t.end(), data[i].a) - t.begin()].push_back(data + i);
        links[lower_bound(t.begin(), t.end(), data[i].b) - t.begin()].push_back(data + i);
    }
#ifdef _DEBUG
    for (int i = 0; i < len; i++)
        cout << t[i] << ' ';
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < links[i].size(); j++)
            cout << links[i][j]->a << ' ' << links[i][j]->b << '|';
        cout << endl;
    }
#endif
    for (int i = 0; i < len; i++)
    {
#ifdef _DEBUG
        cout << S.size() << endl;
        for (int j = 0; j < S.size(); j++)
            cout << S[j] << ' ';
        cout << endl;
#endif
        for (int j = 0; j < links[i].size(); j++)
        {
            if (links[i][j]->a == t[i])
            {
                if (!S.empty())
                {
#ifdef _DEBUG
                    cout << S[S.size() - 1]->h << ' ' << links[i][j]->h << endl;
#endif
                    if (S[S.size() - 1]->h < links[i][j]->h)
                        S.push_back(links[i][j]);
                }
                else
                {
                    S.push_back(links[i][j]);
                }
            }
            else if (links[i][j]->b == t[i])
            {
                for (int k = 0; k < S.size(); k++)
                    if (S[k]->h == links[i][j]->h)
                    {
                        cout<<'E'<<t[i]<<' '<<S[k]->h<<' '<<links[i][j]->h<<endl;
                        S.erase(S.begin() + k);
                        break;
                    }
            }
        }
        if (!S.empty())
            result[i] = S[S.size() - 1]->h;
    }
#ifdef _DEBUG
    for (int i = 0; i < len; i++)
        cout << result[i] << ' ';
    cout << endl;
#endif
    for (int i = 0; i < len - 1; i++)
        ans += (t[i + 1] - t[i]) * result[i];
    cout << ans;
    return 0;
}