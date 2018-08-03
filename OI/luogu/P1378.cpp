#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 100000000.0
using namespace std;
int n,a_x,a_y,b_x,b_y;
const double  PI=acos(-1);
double sum=INF,pw[7];
//0-x 1-y
int p[7][2],pd[7];
double dis(int ax,int ay,int bx,int by)
{
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
double f()
{
    int i,x,y,j;
    double mindis,ans,t;
    ans=abs(a_x-b_x)*abs(a_y-b_y);
    for(i=0;i<n;i++)
        pw[i]=0;
    for(i=0;i<n;i++)
    {
        mindis=INF;
        x=p[pd[i]][0];
        y=p[pd[i]][1];
        mindis=min((double)abs(x-a_x),mindis);
        mindis=min((double)abs(x-b_x),mindis);
        mindis=min((double)abs(y-a_y),mindis);
        mindis=min((double)abs(y-b_y),mindis);
        for(j=0;j<i;j++)
        {
            t=dis(x,y,p[pd[j]][0],p[pd[j]][1])-pw[j];
            if(t<0)
                mindis=0;
            else
                mindis=min(t,mindis);
        }
        //cout<<i<<'-'<<mindis<<endl;
        pw[i]=mindis;
        ans-=PI*(mindis*mindis);
    }
    return ans;
}
int fact(int x)
{
    int sum=1,i;
    for(i=1;i<=x;i++)
    {
        sum*=i;
    }
    return sum;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,t;
    double re;
    cin>>n;
    cin>>a_x>>a_y>>b_x>>b_y;
    for(i=0;i<n;i++)
        cin>>p[i][0]>>p[i][1];
    for(i=0;i<n;i++)
        pd[i]=i;
    for(i=0;i<fact(n);i++)
    {
        re=f();
        //cout<<re<<endl;
        sum=min(sum,re);
        /*for(j=0;j<n;j++)
            cout<<pd[j]<<' ';
        cout<<endl;*/
        next_permutation(pd,pd+n);                
    }
    cout<<(int)(sum+0.5)<<endl;
    return 0;
}
