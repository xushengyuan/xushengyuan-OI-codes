//Date:2018/3/12
//OJ:luogu
//Problem:1320
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n=0;
string str;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string t;
    while(cin>>t)
    {
        str.append(t);
        n++;
    }
    cout<<n<<' ';
    int p=0,flag=0;
    while(p<str.size())
    {
        int t=0;
        while(p+t<str.length() && str[p+t]-'0'==flag)
            t++;
        p+=t;
        cout<<t<<' ';
        flag=flag^1;
    }
    return 0;
}