//Date:2018/2/16
//OJ:Codeforces
//Problem:EDU 38 B
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define MAXN 100010
using namespace std;
int n;
int data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    data[0]=1;
    data[n+1]=1000000;
    int _min=0x7fffffff;
    for(int i=1;i<=n+1;i++)
        _min=min(_min,max(data[i-1]-1,1000000-data[i]));
    cout<<_min;
    return 0;
}