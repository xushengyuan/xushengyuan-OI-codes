//Date:2018/9/6
//OJ:luogu
//Problem:4147
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define sq(x) x*x
#define MAXN 1010
using namespace std;
int n,m,resultA=1,resultB=0;
bool data[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN],u[MAXN][MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(u,0,sizeof(u));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int ch;
            cin>>ch;
            data[i][j]=ch==0?false:true;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            //if(data[i][j])
            {
                u[i][j]=1;
                l[i][j]=j;
                r[i][j]=j;
            }
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            if(data[i][j-1])
                l[i][j]=l[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=m-1;j>=1;j--)
            if(data[i][j+1])
                r[i][j]=r[i][j+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i>1 && data[i-1][j])
            {
                l[i][j]=max(l[i][j],l[i-1][j]);
                r[i][j]=min(r[i][j],r[i-1][j]);
                u[i][j]=u[i-1][j]+1;
            }
            if(data[i][j])
            {
                int len=r[i][j]-l[i][j]+1;
                resultB=max(resultB,min(u[i][j],len));
            }
        }
    cout<<resultB;
    return 0;
}