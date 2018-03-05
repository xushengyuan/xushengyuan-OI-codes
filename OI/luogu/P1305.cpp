//Date:2018/3/4
//OJ:luogu
//Problem:1305
//Solution:tree
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1000
using namespace std;
int n;
char data[MAXN],ls[MAXN],rs[MAXN];
void out(int ch)
{
    if(ch=='*')
        return ;
    for(int i=0;i<n;i++)
        if(data[i]==ch)
        {
            cout<<data[i];
            out(ls[i]);
            out(rs[i]);
        }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i]>>ls[i]>>rs[i];
    out(data[0]);
    return 0;
}