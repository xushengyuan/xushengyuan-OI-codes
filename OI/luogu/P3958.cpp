//NOIP2017 TG Day2 A
//Date: 2017/11/12
//By: xushengyuan
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<cmath>
#define MAXN 1010
#define ld long double
using namespace std;
int t;
int n,h,r;
struct hole
{
    double x,y,z;
    bool isConnectUP,isConnectDOWN;	
}holes[MAXN];
bool visit[MAXN];
//type=1 -> UP
//type=2 -> DOWN
inline bool isConnectSurface(hole x,int type)
{
    if(type==1)
        if(h-x.z<=r)
            return true;
        else
            return false;
    else if(type==2)
        if(x.z<=r)
            return true;
        else
            return false;
}
inline ld sq(double x)
{
    return x*x;
}
inline bool isConnect(hole a,hole b)
{
    ld dist=sqrt(sq(a.x-b.x)+sq(a.y-b.y)+sq(a.z-b.z));
    //cout<<dist<<endl;
    if(dist-(ld)r*2<=1E-15)
        return true;
    else
        return false;
}
bool flag=false;
void dfs(int u)
{
    if(holes[u].isConnectUP)
    {
        flag=true;
        return;
    }
    visit[u]=true;
    for(int i=0;i<n;i++)
    {
        if(flag)
            return;
        if(!visit[i]&&isConnect(holes[u],holes[i]))
            dfs(i);
    }
}
bool cmp(hole x,hole y)
{
    return x.z<y.z;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        memset(holes,0,sizeof(holes));
        memset(visit,0,sizeof(visit));
        flag=false;
        cin>>n>>h>>r;
        for(int j=0;j<n;j++)
        {
            cin>>holes[j].x>>holes[j].y>>holes[j].z;
            holes[j].isConnectUP=isConnectSurface(holes[j],1);
            holes[j].isConnectDOWN=isConnectSurface(holes[j],2);
        }
        sort(holes,holes+n,cmp);
        for(int i=0;i<n;i++)
            if(holes[i].isConnectDOWN)
                dfs(i);
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;	
    }
    return 0;
}
