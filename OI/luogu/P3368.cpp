//Date:2018/2/8
//OJ:luogu
//Problem:3368
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
    int p=0;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        add(i+1,t-p);
        p=t;
    }
    for(int i=0;i<m;i++)
    {
        int t,x,y,k;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%d%d",&x,&y,&k);
            add(x,k);
            add(y+1,-k);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",sum(x));
        }
    }
    return 0;
}