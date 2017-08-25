//Date:2017/8/17
//OJ:luogu
//Problem:1631
//Solution:Heap
//By:xushengyuan
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define MAXN 100100
using namespace std;
struct nu
{
    int num,m;
};
bool operator<(nu const& a, nu const& b) 
{
    return a.num>b.num;
}

priority_queue<nu/*,vector<nu>,greater<nu> */>q;
int a[MAXN],b[MAXN],n,c[MAXN]={0};
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",sdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    nu tmp;
    for(int i=0;i<n;i++)
        a[i]=read_int() ;
    for(int i=0;i<n;i++)
    {
        b[i]=read_int();
        tmp.num=a[0]+b[i];
        tmp.m=i;
        q.push(tmp);
        //cout <<tmp.num<<endl;
    }
    int f;
    for(int i=0;i<n;i++)
    {
        cout <<q.top().num<<' ';
        f=q.top().m;
        q.pop();
        tmp.num=a[++c[f]]+b[f];
        tmp.m=f;
        q.push(tmp);
    }
    return 0;
}