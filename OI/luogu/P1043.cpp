#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n;
int data[120],data_sum[120][120]={0},f[100][100];
int tot=0;
int dp_max(int x)
{
    int i,j,k,max_sum=0;//f[i][j]为前i个数分成j份获得的最大价值
    memset(f,-1,100*100*sizeof(int));
    for(i=0;i<n;i++)
        f[i][1]=(data_sum[x][x+i]%10+10)%10;
    f[0][0]=1;
    for(i=2;i<=m;i++)//枚举段数
    {
        for(j=i;j<=n;j++)
        //枚举前j个数
        //因为每段至少一个数，所以从i开始枚举
        {
            for(k=i-1;k<j;k++)//枚举分割点位置从i-1个到j-1个
            {
                f[j][i]=max(f[j][i],f[k][i-1]*(data_sum[x+k][x+j]%10+10)%10);
                cout<<tot++<<' '<<f[j][i]<<endl;
            }
        }
    }                                                                                                                                                                                                                                                                                   
    return f[n][m] ;
}
int dp_min()
{
    int f[100][100],i,j,k,min_sum;

    return min_sum;
}
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>m;
    cout<<"n="<<n<<" m="<<m<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>data[i];
        data[i+n]=data[i];
    }
    int j,k;
    for(i=0;i<2*n;i++)
        for(j=i;j<2*n;j++)
            for(k=i;k<=j;k++)
                data_sum[i][j]+=data[k];//预先计算data_sum[a][b]为ai加到bi的和
    /*for(i=0;i<2*n;i++)
        for(j=i;j<2*n;j++)
            cout<<i<<'-'<<j<<"->"<<data_sum[i][j]<<endl;*/
    int max_sum=-1,min_sum=2000000000;
    for(i=0;i<n;i++)//枚举起始点
        max_sum=max(max_sum,dp_max(i));
    cout<<"max="<<max_sum<<endl;
    return 0;
}
