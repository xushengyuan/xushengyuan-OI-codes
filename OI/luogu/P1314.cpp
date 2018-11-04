//Date:2018/9/9
//OJ:luogu
//Problem:1314
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10010
using namespace std;
int n,m;
long long s;
long long w[MAXN],v[MAXN],pren[MAXN],vpre[MAXN],datal[MAXN],datar[MAXN];
long long read_int()
{
    long long result=0;
    char t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
long long check(int W)
{
    memset(pren,0,sizeof(pren));
    memset(vpre,0,sizeof(vpre));
    for(int i=1;i<=n;i++)
        if(w[i]>=W)
            vpre[i]=vpre[i-1]+v[i],pren[i]=pren[i-1]+1;
        else
            vpre[i]=vpre[i-1],pren[i]=pren[i-1];
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int l=datal[i],r=datar[i];
        ans+=(vpre[r]-vpre[l-1])*(pren[r]-pren[l-1]);
    }
    return ans;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m>>s;
    long long Max=0,Min=0x7fffffff;
    for(int i=1;i<=n;i++)
    {
        w[i]=read_int(),v[i]=read_int();
        Max=max(Max,w[i]);
        Min=min(Min,w[i]);
    }
    for(int i=1;i<=m;i++)
        datal[i]=read_int(),datar[i]=read_int();
    int left=Min-1,right=Max+2,mid;
    long long delta,ans=0x7fffffffffffffff;
    while(left<=right)
    {
        mid=(left+right)>>1;
        delta=s-check(mid);
        //cout<<check(mid)<<endl;
        if(delta<0)
            left=mid+1;
        else 
            right=mid-1;
        ans=min(ans,llabs(delta));     
    }
    cout<<ans;
    return 0;
}
