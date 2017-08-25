//Date:2017/8/11
//OJ:luogu
//Problem:1420
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >> n;
    int len=1,t,f,mxn=-1;
    cin >>f;
    for(int i=0;i<n-1;i++)
    {
        cin >>t;
        if(t==f+1)
        {
            f=t;
            len++;
        }
        else
        {
            f=t;
            mxn=max(mxn,len);
            len=1;
        }
    } 
    cout <<mxn;
    return 0;
}