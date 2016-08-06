#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
int a[1000][1000];
int f[1000][1000];
short b[1000][1000];
void DP()
{
    int i,j,t1,t2;
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            t1=f[i+1][j]+a[i][j];
            t2=f[i+1][j+1]+a[i][j];
            if(t1>t2)
            {
                f[i][j]=t1;
                b[i][j]=0;
            }
            else
            {
                f[i][j]=t2;
                b[i][j]=1;
            }
        }
    }
    return ;
}
void print_path()
{
    int t=1,i;
    for(i=1;i<=n;i++)`
    {`
        cout<<a[i][t]<<endl;
        t+=b[i][t];
    }
    return ;
}
int main()
{
    freopen("tower.in","r",stdin);
    //freopen("tower.out","w",stdout);
    memset(f,0,sizeof(int));
    memset(a,0,sizeof(int));
    memset(b,0,sizeof(short));
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            cin>>a[i][j];
    DP();
    cout<<"max="<<f[1][1]<<endl;
    //print_path();
    return 0;
}

