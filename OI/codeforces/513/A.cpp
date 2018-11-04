//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
// #define _DEBUG
#define MAXN 110
using namespace std;
int n;
//int data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string str;
    cin>>n>>str;
    int cot=0;
    for(int i=0;i<n;i++)
        if(str[i]=='8')
            cot++;
    cout<<min(cot,n/11);
    
    return 0;
}