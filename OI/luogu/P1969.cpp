//Date:2017/11/15
//OJ:luogu
//Problem:1969
//Solution: Simula
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int read_int()
{
    int result = 0;
    char t;
    t = getchar();
    while (!isdigit(t))
        t = getchar();
    while (isdigit(t))
    {
        result = result * 10 + t - '0';
        t = getchar();
    }
    return result;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int pre,now,ans=0;;
    pre=0;
    for(int i=0;i<n;i++)
    {
        now=read_int();
        if(now>pre)
            ans+=now-pre;
        pre=now;
    }
    cout<<ans<<endl;
    return 0;
}