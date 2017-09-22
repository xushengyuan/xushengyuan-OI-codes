#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
int a[100005],T,_,i,n,b[100005];
long long ans;
const int MOD=1000000007;
void work(int n,int t)
{
    if (n<=1 || t>29) return;
    int L=0;
    for (int i=1; i<=n; i++) if (a[i]&(1<<t)) b[++L]=a[i];int R=L;
    for (int i=1; i<=n; i++) if (!(a[i]&(1<<t))) b[++R]=a[i];
    for (int i=1; i<=n; i++) a[i]=b[i];
    ans+=1ll*(1<<t)*L*(n-L);
    work(L,t+1); int p=0;
    for (int i=L+1; i<=R; i++) a[++p]=a[i];
    work(p,t+1);
}
int main()
{
    freopen("lowbit.in","r",stdin);
    freopen("lowbit.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    work(n,0);
    printf("%I64d\n",ans*2%MOD);
    return 0;
}
