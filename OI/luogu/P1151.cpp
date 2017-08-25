//Date:2017/8/12
//OJ:luogu
//Problem:1151
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int n,s;
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    cin>>n;
    for(int i=10000 ; i<=30000;i++)
    {
        if(
        (i/100)%n==0&&
        (i/10%1000)%n==0
        &&(i%1000)%n==0)
        {
            cout<<i<<endl;
            s=1;
        }
    }
    if(!s)
        cout<<"No";
    return 0;
}