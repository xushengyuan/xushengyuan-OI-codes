//Date:2018/8/22
//OJ:luogu
//Problem:2397
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,m,cot=0,t;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(cot==0)
            cot=1,t=m;
        else
            cot+=(m==t)?1:-1;
    }
    cout<<t;
    return 0;
}