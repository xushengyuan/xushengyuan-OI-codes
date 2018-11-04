//Date:2018/9/17
//OJ:luogu
//Problem:2312
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
#define ll long long
#define MOD1 1000000007
#define MOD2 19260817
using namespace std;
int data[MAXN];
int n,m;
vector<int>ans;
ll read_int()
{
    ll result=0,flag=1;
    char t=getchar();
    while(!isdigit(t))
    {
        if(t=='-')
            flag=-1;
        t=getchar();
    }
    while(isdigit(t))
    {
        result=(result*10+t-'0')%MOD1;
        t=getchar();
    }
    return result*flag;
}
bool test(ll x)
{
    ll s=0;
    for(int i=n;i>=1;i--)
        s=((data[i]+s)*x)%MOD1;
    s=(s+data[0])%MOD1;
    if(s==0)
        return true;
    else
        return false;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        data[i]=read_int();
    for(int i=1;i<=m;i++)
        if(test(i))
            ans.push_back(i);
    if(ans.empty())
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}