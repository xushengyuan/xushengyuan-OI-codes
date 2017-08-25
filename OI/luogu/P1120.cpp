//Date:2017/8/8
//OJ:luogu
//Problem:1120
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 80
using namespace std;
int n,m=0;
int a[MAXN];
int mi=-1;
bool vis[MAXN]={false};
bool cmp(int a,int b)
{
    return a>b;
}
int dfs(int re,int p,int com,int len)
{
    if(com==m)
    {
        mi=len;
        return 1;
    }
    if(re==0)
    {
        if(dfs(len,0,com+1,len))
            return 1;
    }
    for(int i=p;i<n;i++)
    {
        if(!vis[i] && a[i]<=re)
        {
            vis[i]=true;
            if(dfs(re-a[i],i+1,com,len))
                return 1;
            vis[i]=false;
            if(re==a[i] || re==len)
                break;
            while(a[i]==a[i+1])
                i++;
        }
    }
    return 0;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,sum=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >>t;
        if(t<=50)
        {
            a[m++]=t;
            sum+=t;
        }
    }
    n=m;
    sort(a,a+n,cmp);
    for (size_t i = 1; i <= sum; i++)
    {
        if(sum%i==0)
        {
            m=sum/i;
            if(dfs(i,0,0,i))
                break;
        }
    }
    cout << mi;
    //#ifdef _DEBUG
    //#endif
    return 0;
}