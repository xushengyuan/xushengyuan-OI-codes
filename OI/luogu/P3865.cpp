//Date:2018/2/28
//OJ:luogu
//Problem:3865
//Solution:Spare-Table
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
using namespace std;
int n,m;
int data[MAXN],f[MAXN][40];
// void init()
// {
//     for(int i=0;i<n;i++)
//         f[i][0]=data[i];
//     for(int j=1;(1<<j)<=n;j++)
//         for(int i=0;i<=n-(1<<j)-1;i++)
//             f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//     return ;
// }
// int query(int l,int r)
// {
//     int t=0;
//     while((1<<(t+1))<=r-l+1)
//         t++;
//     return max(f[l][t],f[r-(1<<t)+1][t]);
// }
void init() {
    for(int i = 0; i < n; i++) f[i][0] = data[i];
    for(int j = 1; (1<<j) <= n; j++)
      for(int i = 0; i + (1<<j) - 1 < n; i++)
        f[i][j] = max(f[i][j-1], f[i + (1<<(j-1))][j-1]);
  }
  int query(int L, int R) {
    int k = 0;
    while((1<<(k+1)) <= R-L+1) k++; // 如果2^(k+1)<=R-L+1，那么k还可以加1
    return max(f[L][k], f[R-(1<<k)+1][k]);
  }

int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>data[i];
    init();
    for(int i=0;i<m;i++)
    {
        int l,r;
        l--;
        r--;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}