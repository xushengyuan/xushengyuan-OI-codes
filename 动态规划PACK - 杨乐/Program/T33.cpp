/*
    problem : Luogu 2831
    solution : DP
    
    提交时间 2016-12-05 22:37:36
    耗时/内存 1160ms , 15375kb
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 19;
const int S = 1<<N;
const double eps = 1e-9;

int T, n, m;
double x[N], y[N];
int g[N][N];
int dp[S], mk[S];

int equ(double a, double b){return fabs(a - b) <= eps;}

void work()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%lf%lf", &x[i], &y[i]);
    for(int i=0; i<n; i++)
    {
        g[i][g[i][0]=1] = 1<<i, mk[1<<i] = i;
        for(int j=i+1, r, k, ok; j<n; j++) if(!equ(x[i], x[j]))
        {
            double a = (x[j] * y[i] - x[i] * y[j]) / (x[i] * x[j] * (x[i] - x[j]));
            double b = (y[i] - a * x[i] * x[i]) / x[i];
            if(a >= -eps) continue;
            for(r = (1<<i) | (1<<j), k = j+1; k<n; k++)
                if(equ(a * x[k] * x[k] + b * x[k], y[k])) r |= 1<<k;
            for(ok = 0, k = 1; !ok && k<=g[i][0]; ++k) ok = (r & g[i][k]) == r;
            if(!ok) g[i][++g[i][0]] = r;
        }
    }
    
    int ns = 1<<n;
    for(int i=1; i<ns; i++) dp[i] = n;
    for(int i=0; i<ns; i++)
    {
        int l = (ns-1) ^ i; l = mk[l & (-l)];
        for(int j=1; j<=g[l][0]; j++)
            dp[i | g[l][j]] = min(dp[i | g[l][j]], dp[i] + 1);
    }
    printf("%d\n", dp[ns-1]);
    
    return;
}

int main()
{

    scanf("%d", &T);
    for(int i=1; i<=T; i++) work();
    
    return 0;
}