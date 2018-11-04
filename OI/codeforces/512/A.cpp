//Date:
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
    int cot=0;
    for(int i=0;i<n;i++) 
    {
        int t;
        cin>>t;
        cot+=t;
    }
    if(cot>0)
        cout<<"HARD";
    else
        cout<<"EASY";
    return 0;
}