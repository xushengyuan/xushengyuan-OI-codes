//Date:2017/8/11
//OJ:luogu
//Problem:1156
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
using namespace std;
int d,g;
struct rubbish
{
    int t,f,h;
}data[MAXN];
bool cmp(rubbish a,rubbish b)
{
    return a.t<b.t;
}
bool f[500][5000];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>d>>g;
    for(int i=0;i<g;i++)   
        cin>>data[i].t>>data[i].f>>data[i].h;
    sort(data,data+g,cmp);
    //for(int i=0;i<g;i++)
    //    cout<<data[i].t<<endl;
    int sum;
    for(int i=0;i<g;i++)
        sum+=data[i].f;
    memset(f,0,sizeof(f));
    int t=-1;
    for(int i=1;i<=10;i++)
        f[0][i]=true;
    for(int p=0;p<g;p++)
        for(int high=d-1;high>=0;high--)
            for(int kotori_is_mine=10+sum;kotori_is_mine>=data[p].t;kotori_is_mine--)
            {
                if(f[high][kotori_is_mine]==false)
                    continue;
                f[high+data[p].h][kotori_is_mine]=true;
                f[high][kotori_is_mine+data[p].f]=true;
                if(high+data[p].h>=d)
                {
                    cout<<data[p].t;
                    return 0;
                }
            }
    for(int i=10+sum;i>0;i--)
        if(f[0][i]==true)
        {
            t=i;
            break;
        }
    cout<<max(10,t);
    return 0;
}