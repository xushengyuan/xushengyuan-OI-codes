//Date:2018/8/28
//OJ:luogu
//Problem:1357
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define LL long long int
#define MAXN 65
#define MOD 1000000007
using namespace std;
LL n,m,k;
struct M
{
    LL data[MAXN][MAXN];
}mat;
bool link[MAXN];
int b[MAXN];
M mul(M x,M y,int mm)
{
    M z;
    for(int i=0;i<=mm;i++)
        for(int j=0;j<=mm;j++)
        {
            z.data[i][j]=0;
            for(int k=0;k<=mm;k++)
                z.data[i][j]=(z.data[i][j]+x.data[i][k]*y.data[k][j]%MOD)%MOD;
        }
    return z;
}
void judge(int x,int p)
{
    link[x]=true;
    mat.data[x>>1][x]=1;
    if(x>>1==p && x&1==0)
        return ;
    else
        mat.data[(x>>1)+b[m]][x]=1;
}
void dfs(int p,int q,int x)
{
    // cout<<p<<q<<x<<endl;
    if(p==m+1)
        judge(x,q);
    else
    {
        dfs(p+1,q,x);
        if(q<k)
            dfs(p+1,q+1,x | b[p]);
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m>>k;
    b[1]=1;
    for(int i=2;i<=5;i++)
        b[i]=b[i-1]<<1;
    dfs(1,0,0);
    LL flag=0,mm=(1<<m)-1;
    // for(int i=0;i<=mm;i++)
    //     cout<<link[i]<<' ';
    M result;
    // for(int i=0;i<=mm;i++)
    //     {
    //         for(int j=0;j<=mm;j++)
    //             cout<<mat.data[i][j]<<' ';
    //         cout<<endl;
    //     }
    //     cout<<endl;
    while(n>0)
    {
        if(n&1==1)
        {
            if(flag==0)
            {
                result=mat;
                flag=1;
            }
            else
            {
                result=mul(result,mat,mm);
            }
        }
        mat=mul(mat,mat,mm);
        n>>=1;
        // for(int i=0;i<=mm;i++)
        // {
        //     for(int j=0;j<=mm;j++)
        //         cout<<result.data[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    LL ans=0;
    for(int i=0;i<=mm;i++)
        if(link[i])
            ans=(ans+result.data[i][i])%MOD;
    cout<<ans;
    return 0;
}