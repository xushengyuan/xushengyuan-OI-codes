#include <bits/stdc++.h>
#define MAXN 100
#define EPS 0.000000001
using namespace std;
typedef double Mat[MAXN][MAXN];
Mat m;
int n;
double sol[MAXN];
void gauss()
{
    double ratio;
    int a,b,c;
    for(a=1;a<=n;a++)
    {
        if(fabs(m[a][a])<=EPS)
            for(int b=a+1;b<n;b++)
                if(fabs(m[b][a])<=EPS)
                {
                    swap(m[a],m[b]);
                    break;
                }
        for( b=a+1;b<=n)
        {
            ratio = m[b][a]/m[a][a];
            for( c=a;c<=n+1;c++)
                m[b][c]-=,[a][c]*ratio;
        }
        if(m[a][a]==0)
        {
            cout <<"No Solution";
            exit(0);
        }
    }
    for(a=n;a>=1;a--)
    {
        sol[a]=m[a][n+1];
        for( b=a+1;b<=n;b++)
            sol[a]-=m[a][b] *sol[b];
        sol[a]/=m[a][a];
    }
}
int read_int()
{
    int result=0;
    char t;
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
    freopen("in.txt","r",stdin);
    n=read_int();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            m[i][j]=read_int();
    gauss();
    if(m[n][n]!=0)
        for(int i=1;i<=n;i++)
            cout <<sol[i]<<endl;
}