//Date:2018/9/13
//OJ:luogu
//Problem:1311
//Solution:Stack
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 2000010
#define MAXK 52
using namespace std;
int n,k,p;
int color[MAXN],price[MAXN];
int s[MAXK],cot[MAXK],pre[MAXK];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>k>>p;
    for(int i=0;i<n;i++)
        cin>>color[i]>>price[i];
    int cafe_now,S=0;
    for(int i=0;i<n;i++)
    {
        if(price[i]<=p)
            cafe_now=i;
        if(cafe_now>=pre[color[i]])
            s[color[i]]=cot[color[i]];
        pre[color[i]]=i;
        S+=s[color[i]];
        cot[color[i]]++;
    }
    cout<<S;
    return 0;
}