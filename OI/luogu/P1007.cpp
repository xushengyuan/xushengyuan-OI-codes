//Date:2017/8/28
//OJ:luogu
//Problem:1007
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int l,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>l>>n;
    int t,f;
    int _max=0,_min=0;
    for(int i=0;i<n;i++)
    {
        cin >>t;
        f=l-t+1;
        _max=max(_max,max(t,f));
        _min=max(_min,min(t,f));
    }
    cout <<_min<<' '<<_max<<endl;
    return 0;
}