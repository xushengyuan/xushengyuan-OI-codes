//Date:2018/5/11
//OJ:UVa
//Problem:11538
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
unsigned long long m,n,ans;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            return 0;
        else if(m<n)
            swap(m,n);
        ans=2*n*(n-1)*(3*m-n-1)/3+n*m*(n-1)+n*m*(m-1);
        cout<<ans<<endl;
    }
    return 0;
}