//Date:2017/9/25
//OJ:luogu
//Problem:1356
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int mo(int x,int p) {return x%p<0?(x%p)+p:x%p;}
int m;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>m;
    bool f[110*100][MAXN];
    for(int t=0;t<m;t++)
    {
        int n,k;
        cin>>n>>k;
        int tmp;
        cin>>tmp;
        memset(f,0,sizeof(f))        ;
        f[0][mo(tmp,k)]=true;
        f[0][mo(-tmp,k)]=true;
        for(int i=1;i<n;i++)
        {
            cin>>tmp;
            for(int j=0;j<k;j++)
                f[i][j]=f[i-1][mo(j-tmp,k)]||f[i-1][mo(j+tmp,k)];
        }
        if(f[n-1][0])
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;
    }

    return 0;
}