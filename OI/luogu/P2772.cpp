//Date:2017/10/8
//OJ:luogu
//Problem:2772
//Solution:单调队列
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
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
int n;
pair<int,int> data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
    {
        data[i].first=read_int();
        data[i].second=read_int();
    }
    sort(data,data+n);
    deque<pair<int,int> > q;
    q.push_back(data[0]);
    for(int i=1;i<n;i++)
    {
        while(!q.empty() && q.back().second<=data[i].second)
            q.pop_back();
        q.push_back(data[i]);
    }
    while(q.size()>1)
    {
        cout<<'('<<q.front().first<<','<<q.front().second<<')'<<',';
        q.pop_front();
    }
    cout<<'('<<q.front().first<<','<<q.front().second<<')';
    return 0;
}