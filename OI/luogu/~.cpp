#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int n,m,Max,Min;
int sum[201],f[200][20],g[200][20],num[201];
int tot=0;
void dp(int a[])
{
    for (int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];    
    for (int i=0; i<=n; i++)    
        for (int j=0; j<=m; j++)
        {
            f[i][j]=0;
            g[i][j]=999999999;
        }
    for (int i=1; i<=n; i++)     
        f[i][1]=g[i][1]=(sum[i]%10+10)%10;
    f[0][0]=g[0][0]=1; 
    for (int j=2; j<=m; j++)    
        for (int i=j; i<=n; i++)    
            for (int k=j-1; k<=i-1; k++)  
            {
                f[i][j]=max(f[i][j],f[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
                cout<<tot++<<' '<<f[i][j]<<endl;
                g[i][j]=min(g[i][j],g[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
            }
    Max=max(Max,f[n][m]);   
    Min=min(Min,g[n][m]);  
}
int main()
{
    freopen("in.txt","r",stdin);
    Max=0;
    Min=999999999;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
        num[i+n]=num[i];    
    }
    for (int i=0; i<n; i++) dp(num+i); 
    printf("%d\n%d\n",Min,Max);
    return 0;
}
