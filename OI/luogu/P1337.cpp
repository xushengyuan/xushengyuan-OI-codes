//Date:2018/8/21
//OJ:luogu
//Problem:1337
//Solution:simulate_anneal
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10010
#define Delta 0.99
#define EPS 1e-15
#define TEMP 2500
using namespace std;
int n;
double ansX=0.0,ansY=0.0,Ep=1e20;
struct node
{
    int x,y,w;
};
node data[MAXN];
double calcEp(double x,double y)
{
    double s=0.0;
    for(int i=0;i<n;i++)
    {
        double dx=x-data[i].x,dy=y-data[i].y;
        s+=data[i].w*sqrt(dx*dx+dy*dy);
    }
    return s;
}
void sa()
{
    double x=ansX,y=ansY;
    double t=TEMP;
    while(t>EPS)
    {
        double pX=ansX+(rand()*2-RAND_MAX)*t,pY=ansY+(rand()*2-RAND_MAX)*t;
        double pEp=calcEp(pX,pY);
        if(pEp<Ep)
        {
            ansX=x=pX,ansY=y=pY;
            Ep=pEp;
        }
        else if(exp((Ep-pEp)/t)*RAND_MAX>rand())
            x=pX,y=pY;
        t*=Delta;
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
        cin>>data[i].x>>data[i].y>>data[i].w;
    for(int i=0;i<5;i++)
    {
        srand (time(NULL)+i*100);
        sa();
    }
    printf("%.3lf %.3lf",ansX,ansY);
    return 0;
}