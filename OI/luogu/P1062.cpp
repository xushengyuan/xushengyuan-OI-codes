//Date:2018.8.3
//OJ:luogu
//Problem:1062
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1010
using namespace std;
int data[MAXN],p=0;
int k,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>k>>n;
    while(n!=0)
    {
        data[p++]=n&1;
        n>>=1;
    }
    long long result=0;
    p--;
    while(p>=0)
    {
        result+=data[p]*pow(k,p);
        p--;
    }
    cout<<result;
    return 0;
}