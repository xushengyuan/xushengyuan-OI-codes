//Date:2018/8/19
//OJ:luogu
//Problem:3389
//Solution:Gaussian Elimination
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 100
#define EPS 0.000000001
using namespace std;
typedef double Mat[MAXN][MAXN];
Mat m;
int n;
void gauss()
{
    double ratio;
    int i;
    for(i=1;i<=n;i++)
    {
        int t=i;
        for(int j=i;j<=n;j++)
            if(fabs(m[j][i]-m[t][i])<=EPS)
                t=j;
        for(int j=1;j<=n+1;j++)
            swap(m[i][j],m[t][j]);
        if(fabs(m[i][i])<=EPS)
        {
            cout <<"No Solution";
            exit(0);
        }
        /*for(int ii=1;ii<=n;ii++)
        {
            for(int jj=1;jj<=n;jj++)
                cout <<m[ii][jj]<<' ';
            cout<<endl;
        }
        cout<<endl;*/
        for(int j=i+1;j<=n+1;j++)
            m[i][j]/=m[i][i];
        for(int j=1;j<=n;j++)
            if(i!=j)
                for(int k=i+1;k<=n+1;k++)
                    m[j][k]-=m[j][i]*m[i][k];
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            cin>>m[i][j];
    gauss();
    if(m[n][n]!=0)
        for(int i=1;i<=n;i++)
            printf("%.2lf\n",m[i][n+1]);
}