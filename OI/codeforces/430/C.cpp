//Date:2017/8/30
//OJ:codeforces
//Problem:430-C
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 200100
using namespace std;
int fa[MAXN],depth[MAXN];
int gcds[MAXN];
int data[MAXN],n,f[MAXN];
vector<int> son[MAXN];
vector<int> dep[MAXN];
vector<int> node[MAXN];
bool vis[MAXN]={false};
int max_depth=-1;
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
void dfs(int p,int dpt)
{
    max_depth=max(max_depth,dpt);
    depth[p]=dpt;
    dep[dpt].push_back(p);
    vis[p]=true;
    bool flag=false;
    for(int i=0;i<node[p].size();i++)
        if(!vis[node[p][i]])
        {
            flag=true;
            son[p].push_back(node[p][i]);
            fa[node[p][i]]=p;
            dfs(node[p][i],dpt+1);
        }
    return;
}
int g(int x,int y)
{
    if(y==0) return x;
    g(y,x%y);
}
int gcd(int x,int y)
{
    if(x==0)
        return y;
    else if(y==0)
        return x;
    else
        return g(x,y);
}

int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    cin >>n;
    for(int i=0;i<n;i++)
        data[i]=read_int();
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        x=read_int();
        x--;
        y=read_int();
        y--;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dfs(0,0);
    /*for(int i=0;i<=max_depth;i++)
    {
        for(int j=0;j<dep[i].size();j++)
            cout <<dep[i][j]<<' ';
        cout <<endl;
    }*/
    gcds[0]=data[0];
    for(int i=0;i<=max_depth;i++)
        for(int j=0;j<dep[i].size();j++)
            gcds[dep[i][j]]=gcd(data[dep[i][j]],gcds[fa[dep[i][j]]]); 
    int p;
    f[0]=0;
    for(int i=1;i<=max_depth;i++)
        for(int j=0;j<dep[i].size();j++)
        {
            p=dep[i][j];
            f[p]=max(gcds[fa[p]],gcd(f[fa[p]],data[p]));
        }
    cout <<data[0]<<' ';
    for(int i=1;i<n;i++)
        cout <<f[i]<<' ';
    return 0;
}