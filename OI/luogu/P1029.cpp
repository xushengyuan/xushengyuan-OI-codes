//Date:2018/2/18
//OJ:luogu
//Problem:1029
//Solution:MAth
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,m;
int gcd(int x,int y)
{
    if(y==0)    
        return x;
    else
        return gcd(y,x%y);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    int cot=0;
    for(int i=1;i<=ceil(sqrt(m*n));i++)
    {
        if((n*m)%i!=0)
            continue;
        if(gcd(i,(n*m)/i)==n)
            cot+=2;
    }
    cout<<cot;
    return 0;
}