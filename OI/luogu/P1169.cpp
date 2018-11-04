//Date:2018/8/29
//OJ:luogu
//Problem:1169
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define sq(x) x*x
#define MAXN 2010
using namespace std;
int n,m,resultA=1,resultB=1;
bool data[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN],u[MAXN][MAXN];
int read_int()
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            data[i][j]=read_int()==0?false:true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            u[i][j]=1;
            l[i][j]=j;
            r[i][j]=j;
        }
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            if(data[i][j]!=data[i][j-1])
                l[i][j]=l[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=m-1;j>=1;j--)
            if(data[i][j]!=data[i][j+1])
                r[i][j]=r[i][j+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i>1)
            {
                if(data[i][j]!=data[i-1][j])
                {
                    l[i][j]=max(l[i][j],l[i-1][j]);
                    r[i][j]=min(r[i][j],r[i-1][j]);
                    u[i][j]=u[i-1][j]+1;
                }
            }
            int len=r[i][j]-l[i][j]+1;
            resultA=max(resultA,sq(min(u[i][j],len)));
            resultB=max(resultB,u[i][j]*len);
        }
    cout<<resultA<<endl<<resultB<<endl;
    return 0;
}