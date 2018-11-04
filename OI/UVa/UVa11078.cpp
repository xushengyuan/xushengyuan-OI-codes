//Date:2018/9/7
//OJ:UVa
//Problem:11078
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define INF 0x7fffffff
#define MAXN 100010
using namespace std;
int n,t,data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>data[i];
        int Max=data[0],ans=data[0]-data[1];
        for(int i=1;i<n;i++)
        {
            ans=max(ans,Max-data[i]);
            Max=max(Max,data[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}