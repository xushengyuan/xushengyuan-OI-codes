//Date:2017/8/29
//OJ:Codeforces
//Problem:430-A
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int l,r,x,y,k;
    cin >>l>>r>>x>>y>>k;
    double mx=r/x, mn=l/y;
    if(k<=mx && k>=mn)
    {
        for(int i=l/k>x?l/k:x;i<=y && i<=r/k && k*i<=r;i++) 
            if(i*k<=r && i*k>=l)
            {
                cout <<"YES";
                exit(0);
            }
        cout <<"NO";
    }
    else
        cout <<"NO";
    return 0;
}