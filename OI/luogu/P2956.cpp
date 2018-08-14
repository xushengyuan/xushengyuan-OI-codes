//Date:2018/8/13
//OJ:luogu
//Problem:2956
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 250
using namespace std;
bool vis[MAXN][MAXN];
int n,x,y;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>x>>y>>n;
    memset(vis,0,sizeof(vis));
    for(int k=0;k<n;k++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                vis[i][j]=true;
    }
    int ans=0;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            ans+=vis[i][j]?1:0;
    cout<<ans;
    return 0;
}