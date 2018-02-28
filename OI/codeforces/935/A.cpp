//Date:2018/2/20
//OJ:Codeforces
//Problem:935 A
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
    int cot=0;
    for(int i=1;i<n;i++)
        if((n-i)%i==0)
            cot++;
    cout<<cot;
    return 0;
}