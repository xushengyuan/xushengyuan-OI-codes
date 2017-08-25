//Date:2017/8/14
//OJ:luogu
//Problem:3378
//Solution:Heap
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
multiset<int>q;
int n;
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
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int x=read_int(),y;
        switch(x)
        {
        case 1:
            y=read_int();
            q.insert(y);
            break;
        case 2:
            cout <<*q.begin()<<endl;
            break;
        case 3:
            q.erase(q.begin());
            break;
        }
    }
    return 0;
}