#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n;
int data[120],data_sum[200]={0},f[100][100],sum[200]={0};
int tot=0;

int dp_max(int data_temp[])
{
    int i,j,k,max_sum=0;//f[i][j]为前i个数分成j份获得的最大价值
    for (int i=1; i<=n; i++) 
        data_sum[i]=data_sum[i-1]+data_temp[i];
    for (int i=0; i<=n; i++)    
        for (int j=0; j<=m; j++)
            f[i][j]=0;
    for(i=0;i<n;i++)
        f[i][1]=(data_sum[i]%10+10)%10;
    f[0][0]=1;
    for(i=2;i<=m;i++)//枚举段数
    {
        for(j=i;j<=n;j++)
        //枚举前j个数
        //因为每段至少一个数，所以从i开始枚举
        {
            for(k=i-1;k<j;k++)//枚举分割点位置从i-1个到j-1个
            {
                f[j][i]=max(f[j][i],f[k][i-1]*(((data_sum[j]-data_sum[k])%10+10)%10));
                //cout<<tot++<<' '<<f[j][i]<<endl;
            }
        }
    }                                                                                                                                                                                                                                                                                   
    return f[n][m] ;
}
int dp_min(int data_temp[])
{
    int i,j,k,max_sum=0;//f[i][j]为前i个数分成j份获得的最大价值
    for (int i=1; i<=n; i++) 
        data_sum[i]=data_sum[i-1]+data_temp[i];
    for (int i=0; i<=n; i++)    
        for (int j=0; j<=m; j++)
            f[i][j]=2000000000;
    for(i=0;i<n;i++)
        f[i][1]=(data_sum[i]%10+10)%10;
    f[0][0]=1;
    for(i=2;i<=m;i++)//枚举段数
    {
        for(j=i;j<=n;j++)
        //枚举前j个数
        //因为每段至少一个数，所以从i开始枚举
        {
            for(k=i-1;k<j;k++)//枚举分割点位置从i-1个到j-1个
            {
                f[j][i]=min(f[j][i],f[k][i-1]*(((data_sum[j]-data_sum[k])%10+10)%10));
                //cout<<tot++<<' '<<f[j][i]<<endl;
            }
        }
    }                                                                                                                                                                                                                                                                                   
    return f[n][m];
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n>>m;
    // cout<<"n="<<n<<" m="<<m<<endl;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>data[i];
        data[i+n]=data[i];
    }
    int j,k;
    int max_sum=-1,min_sum=2000000000;
    for(i=0;i<n;i++)//枚举起始点
        max_sum=max(max_sum,dp_max(data+i));
    for(i=0;i<n;i++)//枚举起始点
        min_sum=min(min_sum,dp_min(data+i));
    cout<<min_sum<<endl<<max_sum<<endl;
    return 0;
}
