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
int data[MAXN],f[MAXN][21];
inline int read_int()
{
    int result=0;
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
void init()
{
    for(register int i=0;i<n;i++)
        f[i][0]=data[i];
    for(register int j=1;(1<<j)<=n;j++)
        for(register int i=0;i<=n-(1<<j)+1;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    return ;
}
inline int _query(int l,int r)
{
    int t=0;
    //while((1<<(t+1))<=r-l+1)
    //    t++;
    t=(int)(log2(r-l+1));
    return max(f[l][t],f[r-(1<<t)+1][t]);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(register int i=0;i<n;i++)
        data[i]=read_int();
    init();
    for(register int i=0;i<m;i++)
    {
        int l,r;
        l=read_int(),r=read_int();
        printf("%d\n",_query(l-1,r-1));
    }
    return 0;
}