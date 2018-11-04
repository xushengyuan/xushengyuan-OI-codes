//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n,data[110],pre[110];
bool judge(int s)
{
    int p1=0,p2=1;
    while(p2<=n)
    {
        int pp=p2;
        while(p2<=n && pre[p2]-pre[p1]<=s)
            p2++;
        if(p2-1==p1 || pre[p2-1]-pre[p1]!=s)
            return false;
        p1=p2-1;
    }
    return true;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    char t=getchar();
    while(!isdigit(t))
        t=getchar();
    data[1]=t-'0';
    for(int i=2;i<=n;i++)
        data[i]=getchar()-'0';
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+data[i];
    if(pre[n]==0)
    {
            cout<<"YES";
            exit(0);
    }
    for(int i=0;i<pre[n];i++)
        if(judge(i))
        {
            cout<<"YES";
            exit(0);
        }
    cout<<"NO";
    return 0;
}