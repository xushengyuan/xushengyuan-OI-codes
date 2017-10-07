//Date:2017/10/7
//OJ:luogu
//Problem:T4528
//Solution:Sim
//By:xushengyuan
#include <bits/stdc++.h>
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)   
    {
        int t=read_int();
        if(t==m)
            ans++;
    }
    cout<<ans;
    return 0;
}