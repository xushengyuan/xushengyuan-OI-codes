//Date:2017/9/16
//OJ:luogu
//Problem:1563
//Solution: Simulation
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 100100
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
int n,m;
pair<string,int> data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>m;
    for(int i=0;i<n;i++)
        cin>>data[i].second>>data[i].first;
    int d,s,p=0;
    for(int i=1;i<=m;i++)
    {
        cin>>d>>s;
        int tmp=data[p].second +d;
        if(tmp%2==0)
            p=(p-s+n)%n;
        else
            p=(p+s)%n;
    }
    cout <<data[p].first<<endl;
    return 0;
}