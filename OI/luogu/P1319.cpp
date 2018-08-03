//Date:2018/8/3
//OJ:luogu
//Problem:1319
//Solution:Simu
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
    int t,cot=0,flag=0;
    while(cin>>t)
    {
        for(int i=0;i<t;i++)
        {
            cout<<flag;
            cot++;
            if(cot%n==0)
                cout<<endl;
        }
        flag=1^flag;
    }
    return 0;
}