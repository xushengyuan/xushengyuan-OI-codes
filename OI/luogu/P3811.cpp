//Date:2018/8/15
//OJ:luogu
//Problem:3811
//Solution:math-inv
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 3000010
using namespace std;
int inv[MAXN],n,p;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>p;
    inv[1]=1;
    cout<<1<<endl;
    for(int i=2;i<=n;i++)
    {
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
        printf("%d\n",inv[i]);
    }
    return 0;
}