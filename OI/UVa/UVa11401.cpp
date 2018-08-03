//Date:2018/5/11
//OJ:UVa
//Problem:11401
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1000010
#define LL long long
using namespace std;
int n;
LL f[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    f[3]=0;
    for(int i=4;i<=MAXN;i++)
        f[i]=(((i-1)*(i-2))/2-(i-1)/2)/2+f[i-1];
    while(cin>>n )
        if(n>=3)
            cout<<f[n]<<endl;
        else
            break;
    return 0;
}