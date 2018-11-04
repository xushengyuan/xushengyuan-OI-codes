//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MOD 998244353
#define MAXN 1100
#define MAXM 40100
using namespace std;
long long data[MAXN];
int n;
long long f[MAXN][MAXM];
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int _BeginTime=clock();
#endif
    cin >> n;
    long long Min = MAXM, Max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        Min = min(Min, data[i]);
        Max = max(Max, data[i]);
    }
    int Range = 2 * (Max - Min);
    // int Range=20;
    memset(f, 0, sizeof(f));
    long long ans1=0;
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < i; k++)
        {
            int j = data[i] - data[k] + Range / 2;
            f[i][j]= (f[i][j]+f[k][j]+1)%MOD;
            ans1 = (ans1+ f[k][j] + 1)%MOD;
        }
    }
    long long ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= Range; j++)
    //     {
    //         // cout << f[i][j] << ' ';
    //         ans =(ans+ f[i][j])%MOD;
    //     }
    //     // cout << endl;
    // }
    cout<<ans1+n<<endl;
    // cout << ans+n;
#ifdef _DEBUG
    cout<<"----------------------------------------"<<endl;
    cout<<"Running Time: "<<clock()-_BeginTime<<"ms"<<endl;
#endif
    return 0;
}