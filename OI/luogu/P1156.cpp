//Date:2018/8/6
//OJ:luogu
//Problem:1156
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 110
#define _DEBUG
using namespace std;
int d,g;
struct rubb
{
    int t,f,h;
}data[MAXN];
int f[MAXN][MAXN*10];
bool cmp(rubb a,rubb b)
{
    return a.t<b.t;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>d>>g;
    memset(data,0,sizeof(data));
    for(int i=1;i<=g;i++)
        cin>>data[i].t>>data[i].f>>data[i].h;
    sort(data+1,data+1+g,cmp);
    for(int i=1;i<=g;i++)
        for(int j=0;j<=d;j++)
            f[i][j]=-1;
    f[0][0]=10;
    for(int i=1;i<=g;i++)
        for(int j=0;j<=d;j++)
            if(f[i-1][j]>=0)
                if(f[i-1][j]>=data[i].t-data[i-1].t && d-j<=data[i].h)
                {
                    cout<<data[i].t;
                    exit(0);
                }
                else if(f[i-1][j]>=data[i].t-data[i-1].t)
                {
                    f[i][j+data[i].h]=f[i-1][j]-(data[i].t-data[i-1].t);//use
                    f[i][j]=max(f[i][j],f[i-1][j]-(data[i].t-data[i-1].t)+data[i].f);//eat
                }
    int sum=0,i=1,eng=10;
    while(i<=g&&data[i].t-data[i-1].t<=eng)
    {
        eng-=data[i].t-data[i-1].t;
        eng+=data[i].f;
        sum+=data[i].t-data[i-1].t;
        i++;
    }
    cout<<sum+eng;
    return 0;
}