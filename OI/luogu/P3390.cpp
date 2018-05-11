//Date:2018/4/11
//OJ:luogu
//Problem:3390
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1010
#define LL long long 
#define MOD 1000000007
using namespace std;
LL n, k;
LL data[MAXN][MAXN], t[MAXN][MAXN], ans[MAXN][MAXN];
LL read_int()
{
    char t;
    LL result = 0;
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
void multiply(LL M[MAXN][MAXN],LL N[MAXN][MAXN])
{
    memcpy(t,M,MAXN*MAXN*sizeof(LL));
    memset(M,0,MAXN*MAXN*sizeof(LL));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
            {
                M[i][j]=((N[i][k]*t[k][j])%MOD+M[i][j])%MOD;
            }
    return ;
}
void _pow()
{
    LL p = k-1;
    while (p != 0)
    {
        if (p % 2 == 1)
            multiply(ans,data);
        p/=2;
        multiply(data,t);
    }
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            data[i][j] = read_int();
    memcpy(ans, data, sizeof(data));
    _pow();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}