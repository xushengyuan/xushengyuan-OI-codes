//Date:2018/2/7
//OJ:luogu
//Problem:3374
//Solution:BIT
//By:xushengyuan
#include <bits/stdc++.h>
#define lowbit(x) x&-x
#define MAXN 500010
#define _DEBUG
using namespace std;
int data[MAXN],n,m;
int sum(int x)
{
    int result=0;
    while(x>0)
    {
        result+=data[x];
        x-=lowbit(x);
    }
    return result;
}
void add(int x,int y)
{
    while(x<=n)
    {
        data[x]+=y;
        x+=lowbit(x);
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(data,0,sizeof(data));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        add(i+1,t);
    }
    for(int i=0;i<m;i++)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
            add(x,y);
        else
            printf("%d\n",sum(y)-sum(x-1));
    }
    return 0;
}