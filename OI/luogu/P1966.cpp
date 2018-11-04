//Date:2018/10/4
//OJ:luogu
//Problem:1966
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 100010
#define MOD 99999997
#define _DEBUG
using namespace std;
int id[MAXN];
pair<int,int>a[MAXN],b[MAXN];
int tree[MAXN];
int n,cot=0;
inline int lowbit(int x)
{
    return x&(-x);
}
inline void add(int p,int x)
{
    while(p<=n)
    {
        tree[p]+=x;
        p+=lowbit(p);
    }
}
inline int query(int p)
{
    int result=0;
    while(p>=1)
    {
        result+=tree[p];
        p-=lowbit(p);
    }
    return result;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].first;
    for(int i=0;i<n;i++)
        a[i].second=i+1;
    sort(a,a+n,less<pair<int,int> >());
    for(int i=0;i<n;i++)
        cin>>b[i].first;
    for(int i=0;i<n;i++)
        b[i].second=i+1;    
    sort(b,b+n,less<pair<int,int> >());
    memset(id,0,sizeof(id));
    for(int i=0;i<n;i++)
        id[a[i].second]=b[i].second;
    for(int i=n;i>=1;i--)
    {
        cot+=query(id[i]-1);
        add(id[i],1);
        cot%=MOD;
    }
    cout<<cot;
    return 0;
}