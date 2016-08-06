#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n,N;
int a[202];

int DP_max()
{
    int f[202][202]={0};
    int l,i,j,k,temp,max_num=-20000000;
    for(k=0;k<2*n;k++)
        f[k][1]=0;
    for(l=2;l<=n;l++)
    {
        for(i=0;i<=2*n-l;i++)
        {
            f[i][l]=f[i][1]+f[i+1][l-1];
            for(k=2;k<l;k++)
            {
                temp=f[i][k]+f[k+i][l-k];
                f[i][l]=max(temp,f[i][l]);
            }
            for(k=i;k<i+l;k++)
                f[i][l]+=a[k];
        }
    }
    for(k=0;k<n;k++)
        max_num=max(max_num,f[k][n]);
    return max_num;
}
int DP_min()
{
    int f[202][202]={0};
    int l,i,j,k,temp,min_num=20000000;
    for(k=0;k<2*n;k++)
        f[k][1]=0;
    for(l=2;l<=n;l++)
    {
        for(i=0;i<=2*n-l;i++)
        {
            f[i][l]=f[i][1]+f[i+1][l-1];
            for(k=2;k<l;k++)
            {
                temp=f[i][k]+f[k+i][l-k];
                f[i][l]=min(temp,f[i][l]);
            }
            for(k=i;k<i+l;k++)
                f[i][l]+=a[k];
        }
    }
    for(k=0;k<n;k++)
        min_num=min(min_num,f[k][n]);
    return min_num;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int max_s_num,min_s_num;
    int i;
    cin>>n;
    N=n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    if(n<=2)
    {
        if(n==1)
        {
            max_s_num=0;
            min_s_num=0;
        }
        else
        {
            max_s_num=a[0]+a[1];
            min_s_num=a[0]+a[1];
        }
    }
    else
    {
        max_s_num=DP_max();
        min_s_num=DP_min();
    }
    cout<<min_s_num<<endl<<max_s_num;
    return 0;
}