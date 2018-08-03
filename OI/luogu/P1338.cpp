//Date:2018/7/1
//OJ:luogu
//Problem:1338
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 50000
using namespace std;
int n,m;
int data[MAXN];
deque<int>vis;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;   
    memset(data,0,sizeof(data));
    int p=1,t=m;
    while(t>0)
    {
        if(t>=p)
            data[p]=p;
        else
            data[p]=t;
        t-=data[p];
        p++;
        //cout<<data[p]<<endl;
    }
    for(int i=0;i<n;i++)
        vis.push_back(i+1);
    for(int i=n-1;i>=0;i--)
    {
        cout<<vis[data[i]]<<' ';
        vis.erase(vis.begin()+data[i]);
    }

    return 0;
}