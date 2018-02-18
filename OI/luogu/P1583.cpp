//Date:2017/8/16
//OJ:luogu
//Problem:1583
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 20020
#define _DEBUG
using namespace std;
int e[12];
struct p
{
    int w,d=0,c=0;
}people[MAXN];
int n,k;
bool cmp(p a,p b)
{
    if(a.w != b.w)
        return a.w > b.w;
    else
        return a.d < b.d;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>k ;
    for(int i=1;i<=10;i++)
        cin >>e[i];
    for(int i=0;i<n;i++)
    {
        cin >>people[i].w;
        people[i].d=i+1;
    }
    sort(people,people+n,cmp);
    /*for(int i=0;i<k;i++)
        cout <<people[i].w<<' ';
    cout <<endl;*/
    for(int i=0;i<n;i++)
    {
        people[i].c=i%10 +1 ;
        people[i].w+=e[people[i].c];
    }
    sort(people,people+n,cmp);
    /*for(int i=0;i<k;i++)
        cout <<people[i].w<<' ';
    cout <<endl;*/
    for(int i=0;i<k;i++)
        cout <<people[i].d<<' ';
    return 0;
}