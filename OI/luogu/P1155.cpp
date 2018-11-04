//Date:2018/9/5
//OJ:luogu
//Problem:1155
//Solution:bi-color
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1010
using namespace std;
int n;
int data[MAXN],color[MAXN],Min[MAXN];
vector<int>g[MAXN];
int dfs(int u,int p)
{
    color[u]=p;
    int vcolor=(p==1?2:1);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!color[v])
            if(dfs(v,vcolor)==-1)
                return -1;
        if(color[v]!=vcolor)
            return -1;
    }
    return 0;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(Min,0x3f,sizeof(Min));
    memset(color,0,sizeof(color));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i];
    for(int i=n-1;i>=0;i--)
        Min[i]=min(Min[i+1],data[i]);
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(data[i]<data[j] && data[i]>Min[j+1])
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    for(int i=0;i<n;i++)
        if(!color[i])
            if(dfs(i,1)==-1)
            {
                cout<<0<<endl;
                exit(0);
            }
    stack<int>x,y;
    int p=1;
    for(int i=0;i<n;i++)
    {
        if(color[i]==1)
        {
            x.push(data[i]);
            cout<<"a ";
        }
        else
        {
            y.push(data[i]);
            cout<<"c ";
        }
        while((!x.empty() && x.top()==p) || 
            (!y.empty() && y.top()==p))
        {
            if(!x.empty()&&p==x.top())
            {
                x.pop();
                cout<<"b ";
            }
            else
            {
                y.pop();
                cout<<"d ";
            }
            p++;
        }
    }
    return 0;
}