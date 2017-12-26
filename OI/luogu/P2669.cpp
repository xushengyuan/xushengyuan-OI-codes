//Date:2017/12/26
//OJ:luogu
//Problem:2669
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
    int k,p=1,cnt=0,ans=0;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        if(cnt<p)
            cnt++;
        else
        {
            p++;
            cnt=1;
        }
        ans+=p;
    }
    cout<<ans;
    return 0;
}