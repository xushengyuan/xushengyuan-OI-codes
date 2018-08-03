//Date:2018/5/19
//OJ:luogu
//Problem:P2123
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 20010
#define LL long long
using namespace std;
int T;
int n;
LL f[MAXN];
struct node{
    int a,b;
}data[MAXN];
bool cmp(node x,node y)
{
    return min(y.a,x.b)>min(x.a,y.b);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>data[i].a>>data[i].b;
        sort(data,data+n,cmp);
        memset(f,0,sizeof(f));
        LL sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=data[i-1].a;
            f[i]=max(f[i-1],sum)+data[i-1].b;
        }
        cout<<f[n]<<endl;
    }
    return 0;
}