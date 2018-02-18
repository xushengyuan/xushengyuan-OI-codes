//Date:2018/2/14
//OJ:COdeforces
//Problem:462 B
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
const int val[]={1,0,0,0,1,0,1,0,2,1};
int k;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>k;
    if(k>18*2)
    {
        cout<<-1;
        return 0;
    }
    if(k%2==0)
        for(int i=0;i<k/2;i++)
            cout<<8;
    else if(k>=3)
    {
        for(int i=0;i<(k-1)/2;i++)
            cout<<8;
        cout<<0;
    }
    else if(k==1)
        cout<<0;
    return 0;
}