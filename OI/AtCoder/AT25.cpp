//Date:2018/3/7
//OJ:AtCoder
//Problem:25    
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,m;
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
    int _max=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int cot=0;
        for(int j=0;j<m;j++)
            cot+=(read_int()==0?0:1);
        _max=max(_max,cot);
    }
    cout<<_max;
    return 0;
}