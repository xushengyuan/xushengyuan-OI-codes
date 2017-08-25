#include <bits/stdc++.h>
#define MAXN 260
using namespace std;
int n;
int m[MAXN][MAXN];
int f[MAXN][MAXN];
int sum[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string tmp;
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cin >>tmp;
        for (int j = 0; j < n; j++)
            m[i][j]=tmp[j]-'0';
    }
    for (int i = 0; i < n; i++)
        f[i][0]=m[i][0];
    for (int i = 0; i < n; i++)
        f[0][i]=m[0][i];
    memset(sum,0,sizeof(sum));
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        if(m[i][j]==1)
            {
                f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
                sum[f[i][j]]++;
            }
    for (int i = n; i>0; i--)
        sum[i-1]+=sum[i];
    for (int i = 2; i <= n; i++)
        if(sum[i]!=0)
            cout <<i<<' '<<sum[i]<<endl;
    //system("pause");
    return 0;
}