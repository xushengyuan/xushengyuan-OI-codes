//Date:2017/8/16
//OJ:codeforces
//Problem:839-A
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int n,k,sum=0;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>k;
    int t,result=0;
    if(8*n<k)
    {
        cout <<-1;
        return 0;
    }
    for(int i=0;i<n;i++)   
    {
        cin >>t;
        sum+=t;
        int f=min(8,min(k,sum));
        k-=f;
        sum-=f;
        result++;
        if(k==0)
            break;
    }
    if(k==0)
        cout <<result;
    else
        cout <<-1;
    return 0;
}