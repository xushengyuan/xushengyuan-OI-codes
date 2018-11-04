//Date:2018/9/21
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    int a=1,b=1,c=n-2;
    if(c%3==0)
    {
        a=2;
        c--;
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
    return 0;
}