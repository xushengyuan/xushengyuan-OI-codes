#include <bits/stdc++.h>
#define MAXN 10000100
#define MAND 1000000000
using namespace std;
/*
struct job
{
    int p,d;
}works[MAXN];
bool cmp(job a,job b)
{
    return a.d>b.d;
}
priority_queue<int> q;
int n;
int read_int()
{
    int ans=0;
    char tmp;
    while(!isdigit(tmp))
        tmp=getchar();
    while(isdigit(tmp))
    {
        ans=ans*10+tmp-'0';
        tmp=getchar();
    }
    return ans;
}*/
int main()
{
    /*int result=0;
    n=read_int();
    for (int i = 0; i < n; i++)
        works[i].d=read_int(),works[i].p=read_int();
    sort(&works[0],&works[n-1],cmp);
    int i=0,t,p=0;
    for (i=works[0].d; i>=0;i--)
    {
        while(works[p].d==i && p<n)
        {
            q.push(works[i].p);
            p++;
        }
        result+=q.top();
        q.pop();
    }
    cout <<result;
    //system("pause");*/
    int n;
    cin >>n;
    cin >>n;
    cout<<n;
}