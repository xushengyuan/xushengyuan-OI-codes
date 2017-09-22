//Date:2017/9/10
//OJ:luogu
//Problem:2423
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 3110
#define MAXM 3100
using namespace std;
int f[MAXN][MAXM]={-0x7fffffff},data[MAXN];
int n,sum=0;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n;
    fill(&f[0][0],&f[MAXN-1][MAXM-1],-1234567890);
    for(int i=1;i<=n;i++)
    {
        cin >>data[i];
        sum+=data[i];
    }
    f[0][0]=0;
    //cout <<f[1][1]<<endl;
    for(int i=1;i<=n;i++) 
    {
        for(int j=sum;j>=0;j--)
        {
            f[i][j]=max(f[i][j],f[i-1][j]);
            f[i][j]=max(f[i][j],f[i-1][j+data[i]]);
            if(j>=data[i])
                f[i][j]=max(f[i][j],f[i-1][j-data[i]]+data[i]);
            if(j<=data[i])
                f[i][j]=max(f[i][j],f[i-1][data[i]-j]+j);
            //cout <<f[i][j]<<' ';
        }
        //cout <<endl;
    }
    if(f[n][0]!=0)
        cout <<f[n][0] ;
    else    
        cout <<"Impossible";
    return 0;
}