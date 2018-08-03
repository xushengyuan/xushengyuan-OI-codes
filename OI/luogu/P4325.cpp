//Date:2018/8/3
//OJ:luogu
//Problem:4325
//Solution:Set
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 12
#define _DEBUG
using namespace std;
int cot=0;
set<int>S;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    for(int i=0;i<10;i++)
    {
        int t;
        cin>>t;
        t%=42;
        if(S.empty()||S.find(t)==S.end())
            S.insert(t);
    }
    cout<<S.size();
    return 0;
}