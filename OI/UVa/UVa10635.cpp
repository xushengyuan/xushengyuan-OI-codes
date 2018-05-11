//Date:2018/4/19
//OJ:luogu
//Problem:10635
//Solution:DP - LCS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
inline int read_itn()
{
    int result=0;
    char t=getchar();
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
    
    return 0;
}