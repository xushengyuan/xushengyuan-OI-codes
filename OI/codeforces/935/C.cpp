//Date:2018/2/20
//OJ:Codeforces
//Problem:935 C
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
double r,x1,y11,x2,y2;
double _min(double a,double b)
{
    if(a>=b)
        return b;
    else
        return a;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>r>>x1>>y11>>x2>>y2;
    double deltax=x2-x1,deltay=y2-y11;
    if(deltax==0 && deltay==0)
    {
        printf("%.10lf %.10lf %.10lf",x1+r/2,y11,r/2);
        return 0;
    }
    double l=sqrt(deltax*deltax+deltay*deltay);
    double dis=_min(r,l)+r;
    double x3=x1+_min(r,l)*deltax/l;
    double y3=y11+_min(r,l)*deltay/l;
    double x4=x1-r*deltax/l;
    double y4=y11-r*deltay/l;
    double rex=(x3+x4)/2.0,rey=(y3+y4)/2.0,rer=dis/2;
    printf("%.10lf %.10lf %.10lf",rex,rey,rer);
    return 0;
}