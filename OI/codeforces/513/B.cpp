//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
long long n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    if(n<10)
    {
        cout<<n;
        exit(0);
    }
    int ans=0;
    ans+=n%10+10;n/=10;
    n--;
    while(n>=10)
    {
        ans+=n%10;
        n/=10;        
        // n--;
    }
    cout<<ans+n;
    return 0;
}