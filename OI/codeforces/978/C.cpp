//Date:2018/5/19
//OJ:Codeforces
//Problem:978-C
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define LL long long 
#define MAXN 200010
using namespace std;
LL n,m;
LL a[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(LL i=0;i<n;i++)
        cin>>a[i];
    LL p=0,past,b,last;
    cin>>b;
    last=b;
    while(b-a[p]>0)
    {
        b-=a[p];
        p++;
    }
    past=b;
    cout<<p+1<<' '<<b<<endl;
    for(LL i=1;i<m;i++)
    {
        cin>>b;
        LL tmp=b;
        b-=last;
        b+=past;
        last=tmp;
        while(b-a[p]>0)
        {
            b-=a[p];
            p++;
        }
        past=b;
        cout<<p+1<<' '<<b<<endl;
    }
    return 0;
}