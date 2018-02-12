//Date:2018/2/13
//OJ:luogu
//Problem:1765
//Solution:String
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    char ch;
    int ans=0;
    int table[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    while((ch=getchar())!=EOF)
    {
        if(isalpha(ch))
            ans+=table[ch-'a'];
        else
            ans++;
    }
    cout<<ans;
    return 0;
}