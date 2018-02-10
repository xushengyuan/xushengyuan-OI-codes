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
    int pri;
};
bool cmp(task a,task b)
{
    if(a.pri != b.pri)
        return a.pri<b.pri;
    else
        return a.begin>b.begin;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int id,begin,during,pri,time;
    while(scanf("%d%d%d%d",&id,&begin,&during,&pri)!+EOF)
    {
        while(!q.empty())
        {
            task p=q.top();
            q.pop();
            if(time>=begin-q.during)
            {
                q.push({p.id,p.begin,.during-(begin-time),p.pri});
                break;
            }
            else
                cout<<p.id<<' '<<time=time+p.during;
        }
        time=begin;
        q.push({id,begin,during,pri});
    }
    while(!q.empty())
    {
        task p=q.top();
        q.pop();
        cout<<p.id<<' '<<time=time+p.during;
    }
    return 0;
}