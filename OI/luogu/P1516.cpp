//Date:2018/8/24
//OJ:luogu
//Problem:1516
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
long long n,m,x,y,l;
long long exgcd(long long a, long long b, long long *x, long long *y) 
{
     if(b==0)
     {
         *x = 1,*y = 0;
         return a;
     }
     else
     {
         long long r = exgcd(b, a%b, x, y);
         long long t = *x;
         *x = *y;
         *y = t - a/b * *y;
         return r;
     }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>x>>y>>m>>n>>l;
    long long a=x-y,b=n-m;
    if(b<0)
        a=-a,b=-b;
    long long X,Y;
    long long ans=exgcd(b,l,&X,&Y);
    if(a%ans==0)
        cout<<((X*(a/ans))%(l/ans)+(l/ans))%(l/ans)<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}