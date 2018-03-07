//Date:2018/3/6
//OJ:luogu
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 310
using namespace std;
int n;
int data[MAXN],f[MAXN][MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i];
    for(int i=0;i<n;i++)
        data[n+i]=data[i];
    int _max=-1;
    for(int j=1;j<2*n-1;j++)
        for(int i=j-1;j-i<n && i>=0;i--)
            for(int k=i;k<j;k++)
            {
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+data[i]*data[k+1]*data[j+1]);
                _max=max(_max,f[i][j]);
            }
    cout<<_max;
    return 0;
}