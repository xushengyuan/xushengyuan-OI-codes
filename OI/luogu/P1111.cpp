//Date:2017/8/13
//OJ:luogu
//Problem:1111
//Solution:Union-Find
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
int dad[MAXN];
struct node 
{
    int x,y,t;
}nodes[100000];
int n,m;
int find(int x)
{
    return dad[x]==x?x:dad[x]=find(dad[x]);
}
bool cmp(node a,node b)
{
    return a.t<b.t;
}
int read_int()
{
    char t;
    int result=0;
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
void init_set()
{
    for(int i=0;i<n;i++)
        dad[i]=i;
    return;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>m;
    for(int i=0;i<m;i++)
    {
        nodes[i].x=read_int()-1;
        nodes[i].y=read_int()-1;
        nodes[i].t=read_int();
    }
    init_set() ;
    sort(nodes,nodes+m,cmp);
    int result,cot=0;
    for(int i=0;i<m;i++)
    {
        int dada=find(nodes[i].x);
        int dadb=find(nodes[i].y);
        if(dada!=dadb)
        {
            dad[dada]=dadb;
            result=nodes[i].t;
            cot++;
        }
        if(cot+1==n)
        {
            cout <<result;
            return 0;
        }
    }
    cout <<-1;
    return 0;
}