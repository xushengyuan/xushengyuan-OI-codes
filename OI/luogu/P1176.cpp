#include <bits/stdc++.h>
#define MAXN 1010
#define MOD 100003
using namespace std;
bool ma[MAXN][MAXN]={false};
int n,m;
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
int f[MAXN][MAXN]={0};
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int tx,ty;
    cin >>n>>m;
    for (int i = 0; i < m; i++)
        ma[read_int()][read_int()]=true;
    f[1][1]=1;
    for (int i = 1; i <= n; i++)
        for(int j=1;j<=n;j++)
        {
            if(i==1 && j==1) continue;
            if(ma[i][j])
                f[i][j]=0;
            else 
                f[i][j]=(f[i-1][j]+f[i][j-1])%MOD;
        }
    cout <<f[n][n];
    //system("pause");
    return 0;
}