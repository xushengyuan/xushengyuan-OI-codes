//Date:2018/7/5
//OJ:luogu
//Problem:P2577
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 210
using namespace std;
int n;
int f[MAXN][MAXN][2];
struct person
{
    int a,b;
}data[MAXN];
bool cmp(person a,person b)
{
    return a.b>b.b;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i].a>>data[i].b;
    sort(data,data+n,cmp);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j][0]=f[i][j][1]=23333333;
    #ifdef _DEBUG
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<f[i][j][0]<<'/'<<f[i][j][1]<<' ';
        cout<<endl;
    }
    #endif
    f[1][1][0]=data[0].a;
    f[1][1][1]=0;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            int a1=f[i-1][j-1][0],
                a2=f[i-1][j-1][1]+data[i-1].a,
                b1=f[i-1][j][0]+data[i-1].a,
                b2=f[i-1][j][1];
            if(max(a1,a2)>max(b1,b2))
            {
                f[i][j][0]=b1;
                f[i][j][1]=b2;
            }
            else
            {
                f[i][j][0]=a1;
                f[i][j][1]=a2;
            }
        }
    #ifdef _DEBUG
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<f[i][j][0]<<'/'<<f[i][j][1]<<' ';
        cout<<endl;
    }
    #endif
    int _min=2333333,ans=-1;
    for(int i=1;i<=n;i++)
    {
        _min=2333333;
        for(int j=1;j<=i;j++)
            _min=min(_min,max(f[i][j][0],f[i][j][1]));
        ans=max(ans,_min+data[i-1].b);
    }
    cout<<ans;
    return 0;
}