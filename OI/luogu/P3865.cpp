//Date:2018/2/28
//OJ:luogu
//Problem:3865
//Solution:Spare-Table
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1000010
using namespace std;
int n,m;
int data[MAXN],f[MAXN][40];
void init()
{
    for(int i=0;i<n;i++)
        f[i][0]=data[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i<=n-(1<<j)+1;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    return ;
}
inline int _query(int l,int r)
{
    int t=0;
    //while((1<<(t+1))<=r-l+1)
    //    t++;
    t=(int)(log(r-l+1)/log(2));
    return max(f[l][t],f[r-(1<<t)+1][t]);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>data[i];
    init();
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<_query(l,r)<<endl;
    }
    return 0;
}