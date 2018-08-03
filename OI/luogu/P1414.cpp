//Date:2018/5/13
//OJ:luogu
//Problem:1414
//Solution:Math 
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1000010
using namespace std;
int n,_max=-1;
int data[MAXN],tmp[MAXN];
void getr(int x)
{
    int t=sqrt(x);
    for(int i=1;i<=t;i++)
        if(x % i==0)
        {
            data[i]++;
            if(i!=x/i)
                data[x/i]++;
        }
    return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(data,0,sizeof(data));
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        tmp[i]=x;
        _max=max(_max,x);
    }
    for(int i=0;i<n;i++) 
        getr(tmp[i]);
    int x=_max;
    for(int i=1;i<=n;i++)
    {
        while(data[x]<i)
            x--;
        cout<<x<<endl;
    }
    return 0;
}