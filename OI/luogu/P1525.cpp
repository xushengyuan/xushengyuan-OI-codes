//Date:2018/2/10
//OJ:luogu
//Problem:1525
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000100
#define _DEBUG
using namespace std;
int n,m;
struct edge
{
    int u,v,w;
}edges[MAXN];
bool operator <(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}