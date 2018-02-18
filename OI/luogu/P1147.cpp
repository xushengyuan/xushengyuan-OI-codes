//Date:2018/2/18
//OJ:luogu
//Problem:1147
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n/2;i++)
    {
        int sum=0;
        for(int j=i+1;j<=n;j++)
        {
            sum+=j;
            if(sum>n)
            {
                sum=0;
                break;
            }
            else if(sum==n)
            {
                sum=0;
                cout<<i+1<<' '<<j<<endl;
                break;
            }
        }
    }
    return 0;
}