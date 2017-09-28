//Date:2017/9/28
//OJ:luogu
//Problem:1018
//Solution:DP+HP
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
struct BigInteger
{
    static const int max=100;
    int top,mnumb[maxn];
    BI()
    {
        top=0;
        memset(numb,0,sizeof(numb));
    }
    BI(string s)
    {
        memset(numb,0,sizeof(numb));
        top=s.length()-1;
        for(int i=0;i<s.length();i++)
            num[s.length()-i-1]=s[i]-'0';
    }
    print()
    {
        for(int i=0;i<=top;i++)
            cout<<numb[i];
    }
}
BI operator*(BI &x,BI &y)
{
    BI ret;
    ret.top=x.top+y.top;
    for(int i=0;i<=x.top;i++)
        for(int j=0;j<=y.top;j++)
        {
            ret.numb[i+j] += x[i]*y[i];
            ret.numb[i+j+1] += res.numb[i+j]/10;
            res.numb[i+j]%=10;
        }
    for(int i=0;i<=ret.top;i++)
    {
        ret.numb[i+1]=ret.numb[i]/10;
        ret.numb[i]%=10;
    }
    if(ret.numb[ret.top+1]!=0)
        ret.top++;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}