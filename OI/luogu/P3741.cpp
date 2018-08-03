//Date:2018/8/3
//OJ:luogu
//Problem:3741
//Solution:String
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
    int n,cot=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.length()-1;i++)
        if(s[i]=='V'&&s[i+1]=='K')
        {
            s[i]=s[i+1]=' ';
            cot++;
        }
    for(int i=0;i<s.length()-1;i++)
        if((s[i]=='V'&&s[i+1]=='V')||(s[i]=='K'&&s[i+1]=='K'))
        {
            cout<<cot+1;
            return 0;
        }
    cout<<cot;
    return 0;
}