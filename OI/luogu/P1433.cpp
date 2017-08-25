#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAXN 16
#define INF 23333333333.33
using namespace std;
double x[MAXN],y[MAXN];
double d[MAXN][MAXN];
int n;
bool vis[MAXN];
double min_dis=INF;
void dfs(int p,double dis)
{
    if(dis>min_dis)
        return ;
    bool flag=false;
    for(int i=0;i<n;i++)
        if(!vis[i])
        {
            flag=true;
            vis[i]=true;
            dfs(i,dis+d[p][i]);
            vis[i]=false;
        }
    if(!flag)
        min_dis=min(min_dis,dis);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=sqrt(abs((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
    fill(vis,vis+MAXN,false);
    for(int i=0;i<n;i++)
    {
        vis[i]=true;
        dfs(i,sqrt(x[i]*x[i]+y[i]*y[i]));
        vis[i]=false;
    }
    printf("%.2lf",min_dis);
    return 0;
}