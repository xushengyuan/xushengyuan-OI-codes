#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int move[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
int m,n,t,sx,sy,fx,fy,a[6][6],sum=0;
void dfs(int x,int y)
{
    int i;
    if(x<1 || y<1 || x>m || y>n || a[x][y]==1) return;
    if(x==fx && y==fy)
    {
        sum++;
        return;
    }
    for(i=0; i<4; i++)
    {
        a[x][y]=1;
        dfs(x+move[i][0],y+move[i][1]);
        a[x][y]=0;
    }
    return;
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(a,0,6*6*sizeof(int));
    int i,j,tx,ty;
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(i=0; i<t; i++)
    {
        cin>>tx>>ty;
        a[tx][ty]=1;
    }
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }*/
    dfs(sx,sy);
    cout<<sum;
    return 0;
}
