#include <bits/stdc++.h>
#define ll long long
#define MAXN 100000
#define MOD 1000000007
using namespace std;
int n,a[MAXN];
int read_int()
{
    register int ans=0;
    register char tmp;
    while(!isdigit(tmp))
        tmp=getchar();
    while(isdigit(tmp))
    {
        ans=ans*10+tmp-'0';
        tmp=getchar();
    }
    return ans;
}
int main()
{
    freopen("lowbit.in","r",stdin);
    freopen("lowbit.out","w",stdout);
    register int sum=0,t;
    cin >>n;
    for (int i = 1; i <=n; i++)
        //a[i]=i+10;
        a[i]=read_int();
    for(register int i=1;i<=n;i++)
    {
        for(register int j=i;j<=n;j++)
        {
            sum=(sum+((a[i]^a[j])&-(a[i]^a[j]))*2)%MOD;
        }
    }
    cout<<sum;
    return 0;
}