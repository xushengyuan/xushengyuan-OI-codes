//Date:2017/8/13
//OJ:luogu
//Problem:1197
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 400200
#define MAXM 400200
using namespace std;
vector<int> nex[MAXN];
int n,m,k;
int node_x[MAXM],node_y[MAXM];
int ki[MAXN];
int dad[MAXN];
int ans[MAXN];
bool killed[MAXN]={false};
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10 +t-'0';
        t=getchar();
    }
    return result;
}
int count()
{
    int result=0;
    for(int i=0;i<n;i++)
        if(dad[i]==i && !killed[i])
            result++;
    return result;
}
void init_set()
{
    for(int i=0;i<n;i++)
        dad[i]=i;
    return ;
}
int find(int x)
{
    return dad[x]==x?x:dad[x]=find(dad[x]);
}
void un(int x,int y)
{
    int a=find(x),
        b=find(y);
    dad[a]=b;
    return ;
}
void un(int x,int y,int i)
{
    int a=find(x),
        b=find(y);
    if(a != b)
    {
        dad[a]=b;
        ans[i]--;
    }
    return ;
}
int main()
{
    /*#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif*/
    cin >>n>>m;
    for(int i=0;i<m;i++)
    {
        node_x[i]=read_int();
        node_y[i]=read_int();
    }
    cin >>k;
    for(int i=0;i<k;i++)
    {
        ki[i]=read_int();
        killed[ki[i]]=true;
    }
    init_set();
    for(int i=0;i<m;i++)
        if(!killed[node_x[i]] && !killed[node_y[i]])
            un(node_x[i],node_y[i]);
    for(int i=0;i<m;i++)
    {
        nex[node_x[i]].push_back(node_y[i]);
        nex[node_y[i]].push_back(node_x[i]);
    }
    ans[k]=count();
    /*for(int k=0;k<n;k++)
        cout <<dad[k]<<' ';
    cout <<endl;
    for(int k=0;k<n;k++)
        cout <<killed[k]<<' ';
    cout <<endl;*/
    for(int i=k-1;i>=0;i--)
    {
        killed[ki[i]]=false;
        ans[i]=ans[i+1]+1;
        for(int j=0;j<nex[ki[i]].size();j++)
        {
            if(!killed[nex[ki[i]][j]])
            {
                //cout <<'|'<<ki[i]<<'|'<<nex[ki[i]][j]<<endl;
                un(ki[i],nex[ki[i]][j],i);
            }
        }
        /*for(int k=0;k<n;k++)
            cout <<dad[k]<<' ';
        cout <<endl;
        for(int k=0;k<n;k++)
            cout <<killed[k]<<' ';
        cout <<endl;*/
    }
    for(int i=0;i<=k;i++)
        cout <<ans[i]<<endl;
    return 0;
}