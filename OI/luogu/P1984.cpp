//Date:2018/2/9
//OJ:luogu
//Problem:1984
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define Q 420000.0/n
#define _DEBUG
using namespace std;
int n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    double t=Q,result=0;
    for (int i = 1; i <= n; i++)
    {
        result+=t;
        t=t*(1.0-1.0/(double)(2*i));
    }
    printf("%.2lf",result);
    return 0;
}