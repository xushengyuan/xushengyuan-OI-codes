//Date:2018/3/7
//OJ:AtCoder
//Problem:184
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
using namespace std;
int n;
struct point
{
    int x,y;
}points[MAXN];
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    double _max=-1;   
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>points[i].x>>points[i].y;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            _max=max(_max,dis(points[i],points[j]));
    cout<<_max;
    return 0;
}