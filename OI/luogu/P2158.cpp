//Date:2018/3/7
//OJ:luogu
//Problem:2158
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 40010
using namespace std;
int n;
int phi[MAXN];
void init()
{
    phi[1]=1;    
    for(int i=2;i<MAXN;i++) 
        phi[i]=i;
    for(int i=2;i<MAXN;i++)
        if(phi[i]==i)
            for(int j=i;j<MAXN;j+=i)
                phi[j]=phi[j]/i*(i-1);
    return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    init();
    // for(int i=1;i<400;i++)
    //     cout<<phi[i]<<endl;
    int result=0;
    init();
    for(int i=3;i<=n;i++)
        result+=phi[i-1];
    result*=2;
    result+=3;
    cout<<(n==1?0:result);
    return 0;
}