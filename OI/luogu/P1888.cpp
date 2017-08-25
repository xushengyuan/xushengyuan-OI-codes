//Date:2017/8/11
//OJ:luogu
//Problem:1888
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(y==0) return x;
    gcd(y,x%y);
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a,b,c;
    cin >>a>>b>>c;
    int x,y;
    x=min(min(a,b),c);
    y=max(max(a,b),c);
    int g=gcd(x,y);
    cout <<x/g<<'/'<<y/g;
    return 0;
}