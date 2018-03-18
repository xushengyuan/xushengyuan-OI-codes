//Date:2018/3/12
//OJ:luogu
//Problem:2556
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,old=-1,p=0,tmp[9],t,flag=true;
    cin>>n;
    n/=8;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        for(int j=7;j>=0;j--)
            tmp[j]=t%2,t/=2;
        for(int j=0;j<8;j++)
            if(tmp[j]==old)
                p++;
            else
            {
                if(!flag)
                    cout<<128*old+p<<' ';
                flag=false;
                p=1;
                old=tmp[j];
            }
    }
    cout<<128*old+p<<' ';
    return 0;
}