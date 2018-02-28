//Date:2018/2/19
//OJ:luogu
//Problem:1135
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 210
using namespace std;
int n,a,b;
int _map[MAXN][MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(_map,0x3f,sizeof(_map));
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        _map[i][i]=0;
        int t;
        cin>>t;
        int t1=i-t,t2=i+t;
        if(t1>=1 && t1<=n)
            _map[i][t1]=1;
        if(t2>=1 && t1<=n)
            _map[i][t2]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    _map[i][j]=min(_map[i][j],_map[i][k]+_map[k][j]);
    cout<<((_map[a][b]==0x3f3f3f3f)?-1:_map[a][b]);
    return 0;
}