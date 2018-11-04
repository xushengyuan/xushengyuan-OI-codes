//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,m,k;
int f(x1,y1,x2,y2,x3,y3)
{
    int maxx=max(x1,max(x2,x3)),minx=min(x1,min(x2,x3));
    int maxy=max(y1,max(y2,y3)),miny=min(y1,min(y2,y3));
    int s=(maxx-minx)*(maxy-miny)*2;
    s-=abs(x1-x2)*abs(y1-y2);
    s-=abs(x2-x3)*abs(y2-y3);
    s-=abs(x3-x1)*abs(y3-y1);
    return s;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m>>k;
    // if((n*m*2)%k!=0)
    // {
    //     cout<<"NO";
    //     exit(0);
    // }
    // cout<<"YES";
    return 0;
}