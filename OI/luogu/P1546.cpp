//Date:2018/8/7
//OJ:luogu
//Problem:1546
//Solution:Krus
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10000
using namespace std;
int mi[MAXN],weight[MAXN],u[MAXN],v[MAXN],point[MAXN];
int m,n;
/*int getint()
{
    int 
}*/
bool cmp(int a,int b)
{
    return weight[a]<weight[b];
}
int find(int x)
{
    return point[x] == x ? x : point[x] = find(point[x]);
}
void pre()
{
    int i;
    for(i=0;i<n;i++)
        point[i]=i;
    for(i=0;i<m;i++)
        mi[i]=i;
    sort(mi,mi+m,cmp);
    return ;
}
void get()
{
    cin>>n;
    m=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int t;
            cin>>t;
            if(t!=0)
            {
                u[m]=i,v[m]=j,weight[m]=t;
                m++;
            }
        }
    return ;
}
int kruskal()
{
    int i,sum=0;
    int e,e_x,e_y;
    for(i=0;i<m;i++)
    {
        e=mi[i];
        e_x=find(u[e]),e_y=find(v[e]);
        if(e_x!=e_y)
        {
            point[e_x]=e_y;
            sum+=weight[e];
        }
    }
    return sum;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i;
    get();
    pre();
    int ans;
    ans=kruskal();
    cout<<ans;
    return 0;
}