//Date:2017/8/29
//OJ:codeforces
//Problem:430-B
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int r,d,n;
double get_dist(int x,int y)
{
    return sqrt((double)(x*x)+(double)(y*y));
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>r>>d;
    cin>>n;
    int sum=0,R,x,y;
    double dist;
    for(int i=0;i<n;i++)
    {
        cin >>x>>y>>R;
        dist=get_dist(x,y);
        if(dist+R<=r && dist-R>=r-d)
        {
            sum++;
            //cout <<i+1<<endl;
        }
    }
    cout <<sum;
    return 0;
}