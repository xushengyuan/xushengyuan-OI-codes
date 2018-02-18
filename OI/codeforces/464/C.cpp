#include <bits/stdc++.h>
#define MAXN 10
using namespace std;
int n,data[MAXN],s,f;
long long sum[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n;
    cin>>data[1];
    sum[0]=0;
    sum[1]=data[1];
    for(int i=2;i<=n;i++)
    {
        cin>>data[i];
        sum[i]=sum[i-1]+data[i];
    }
    cin>>s>>f;
    long long _max=-1;
    int result;
    for(int i=0;i<n;i++)
    {
        int l,r;
        l=s-i;
        r=f-i-1;
        long long tmp;
        if()
            tmp=sum[r]-sum[l-1+1];
        if(tmp>_max)
        {
            _max=tmp;
            result=i;
        }
    }
    cout<<result;
    return 0;
}