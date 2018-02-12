//Date:2018/2/12
//OJ:luogu
//Problem:1179
//Solution:String
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int l,r;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int ans=0;
    cin>>l>>r;
    for(int i=l;i<=r;i++)   
    {
        char str[10];
        sprintf(str,"%d",i);
        int len=strlen(str);
        for(int j=0;j<len;j++)
            if(str[j]=='2')
                ans++;
    }
    cout<<ans;
    return 0;
}