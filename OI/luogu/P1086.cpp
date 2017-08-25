//Date:2017/8/15
//OJ:luogu
//Problem:1086
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y,w;
}m[450];
int ma[21][21];
int mm,n,k;
bool cmp(point a,point b)
{
    return a.w>b.w;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>mm>>n>>k;
    int tot=0;
    for(int i=0;i<mm;i++)
        for(int j=0;j<n;j++)
        {
            cin >>ma[i][j];
            m[tot].x=i;
            m[tot].y=j;
            m[tot].w=ma[i][j];
            tot++;
        }
    sort(m,m+tot,cmp);
    int result=0;
    if(k-m[0].x-2-m[0].x-1>=0)
    {
        result+=m[0].w;
        k--;
        k-=m[0].x+1;
        for(int i=1;i<tot;i++)
        {
            int dx=abs(m[i-1].x-m[i].x);
            int dy=abs(m[i-1].y-m[i].y);
            if(k-dx-dy-m[i].x-2>=0)
            {
                result+=m[i].w;
                k--;
                k-=dx+dy;
            }
            else
                break;
        }
    }
    cout <<result;
    return 0;
}