//Date:2017/8/25
//OJ:luogu
//Problem:1842
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;
struct cow
{
    int w,s;
}cows[MAXN];
int n;
bool cmp(const cow a,const cow b)
{
    return a.w+a.s>b.w+b.s;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >>cows[i].w>>cows[i].s;
        sum+=cows[i].w;
    }
    sort(cows,cows+n,cmp);
    //for(int i=0;i<n;i++)
    //    cout <<cows[i].w<<' '<<cows[i].s<<endl;
    int _max=0x80000000;
    for(int i=0;i<n;i++)
    {
       sum-=cows[i].w;
       _max=max(_max,sum-cows[i].s);
    }
    cout <<_max;
    return 0;
}