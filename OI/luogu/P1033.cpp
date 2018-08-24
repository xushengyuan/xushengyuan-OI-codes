//Date:2018/8/21
//OJ:luogu
//Problem:1033
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define EPS 1e-5
using namespace std;
double h,s,v,l,k,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>h>>s>>v>>l>>k>>n;
    double tOn=sqrt((h-k)/5),
        tUnder=sqrt(h/5),
        end=(s+l)-tOn*v+EPS,
        begin=s-tUnder*v-EPS;
    int _begin=(int)begin+((double((int)begin)!=begin)?1:0);
    cout<<max((int)(min(n-1,end)-max(_begin,0)+1),0);
    return 0;
}