//Date:2017/10/4
//OJ:luogu
//Problem:1083
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 
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
struct request
{
    int left,right;
    int pos;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}