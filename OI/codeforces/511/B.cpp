//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 100010
//#define _DEBUG
using namespace std;
int n;
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
    cin>>n;
    int Max=0;
    for(int i=0;i<n;i++)
        Max=max(Max,read_int()+read_int());
    cout<<Max;
    return 0;
}