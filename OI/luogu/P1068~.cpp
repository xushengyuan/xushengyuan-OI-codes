#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
struct re
{
    int umi,honoko;
}nico[10000];
int cmp(re a,re b)
{
    if(a.honoko==b.honoko)return a.umi<b.umi;
    return a.honoko>b.honoko;
}
int main()
{
    int n,m,kotori,sum=0;
    cin>>n>>m;
    kotori=m*1.5;
    for(int i=0;i<n;i++)
        cin>>nico[i].umi>>nico[i].honoko;
    sort(nico,nico+n,cmp);
    for(int i=kotori;i<n;i++)
        if(nico[i].honoko==nico[kotori-1].honoko)
            kotori++;
    cout<<nico[kotori-1].honoko<<" "<<kotori<<endl;
    for(int i=0;i<kotori;i++)
        cout<<nico[i].umi<<" "<<nico[i].honoko<<endl;
}
