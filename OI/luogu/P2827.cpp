//Date:2018/9/6
//OJ:luogu
//Problem:2827
//Solution:Queue
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 100010
using namespace std;
int n,m,q,u,v,t;
int data[MAXN];
queue<int>Q[2];
int read_int()
{
    int result=0;
    char t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m>>q>>u>>v>>t;
    double p=(double)u/(double)v;
    for(int i=0;i<n;i++)
        data[i]=read_int();
    sort(data,data+n,greater<int>());
    int pp=0,s=0;
    for(int i=1;i<=m;i++)
    {
        int Max=0;
        if(Q[0].front()>=Q[1].front() && (pp>=n ||Q[0].front()>=data[pp]))
        {Max=Q[0].front();Q[0].pop();}
        else if(Q[0].front()<=Q[1].front() && (pp>=n||Q[1].front()>=data[pp]))
        {Max=Q[1].front();Q[1].pop();}
        else if(pp<n && Q[0].front()<=data[pp] && Q[1].front()<=data[pp])
        {Max=data[pp];pp++;}
        Max+=s;
        if(i%t==0)
             printf("%d ",Max);
        int len1=floor(p*(double)Max),len2=Max-len1;
        s+=q;
        len1-=s,len2-=s;
        Q[0].push(len1);
        Q[1].push(len2);
        //cout<<n-pp+Q[0].size()+Q[1].size()<<endl;
    }
    vector<int>all;
    //cout<<Q[0].size()+Q[1].size()<<endl;
    while(!Q[0].empty())
    {
        all.push_back(Q[0].front());
        Q[0].pop();
    }
    //cout<<all.size()<<endl;
    while(!Q[1].empty())
    {
        all.push_back(Q[1].front());
        Q[1].pop();
    }
    //cout<<all.size()<<endl;
    for(int i=pp;i<n;i++)
        all.push_back(data[i]);
    sort(all.begin(),all.end(),greater<int>());
    cout<<endl;
    for(int i=0;i<all.size();i++)
        if((i+1)%t==0)
            printf("%d ",all[i]+s);
    return 0;
}