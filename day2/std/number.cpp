#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int cnt,i,a[105],b[3000005],o,j,dp[3000005],l,r,p,k,sum;
bool FLAG,v[3000005];
void dfs(int x,int y)
{
    if (x==o+1)
    {
        b[++cnt]=y;
        return;
    }
    dfs(x+1,y);
    for (;;)
    {
        if (1ll*y*a[x]>r) return;
        y*=a[x];
        dfs(x+1,y);
    }
}
int cmp(int i,int j) {return i<j;}
int main()
{
   // freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    scanf("%d%d%d",&l,&r,&p);
    for (i=2; i<=50; i++)
    {
        FLAG=true;
        for (j=2; j<i; j++)
          if (i%j==0) FLAG=false;
        if (FLAG) a[++o]=i;
    }
    dfs(1,1);
    sort(b+1,b+cnt+1,cmp);
    for (i=2; i<=cnt; i++) dp[i]=105;
    for (i=2; i<=p; i++)
    {
        k=1;
        for (j=1; j<=cnt; j++)
          if (b[j] % i==0)
          {
              if (dp[k]+1<dp[j]) dp[j]=dp[k]+1;
              k++;
              if (dp[j]+i<=p) v[j]=1;
          }
    }
    v[1]=1;
    for (i=1; i<=cnt; i++) if (b[i]>=l && v[i]) cout<<i<<' ';
    cout<<sum;
    return 0;
}
