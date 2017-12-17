//Date:2017/11/15
//OJ:luogu
//Problem:2278
//Solution:Heap
//By:xushengyuan
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define _DEBUG
using namespace std;
__gnu_pbds::priority_queue<task,cmp>q;
struct task
{
    int id;
    int begin,during;
    int pro;
};
int n=0;
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
bool cmp(task a,task b)
{
    if(a.pro != b.pro)
        return a.pro<b.pro;
    else
        return a.begin>b.begin;
}
task read_task()
{
    task result;
    result.id=read_int();
    result.begin=read_int();
    result.during=read_int();
    result.pro=read_int();
    return task;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}