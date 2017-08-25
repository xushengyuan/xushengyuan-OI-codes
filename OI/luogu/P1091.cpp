//Date:2017/8/8
//OJ:luogu
//Problem:1091
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int n;
int a[MAXN],fr[MAXN],fl[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        fl[i]=1;
        fr[i]=1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if(a[i]>a[j])
                fl[i]=max(fl[i],fl[j]+1);
    for (int i = n-1; i >= 1; i--)
        for (int j = i+1; j <=n; j++)
            if(a[i]>a[j])
                fr[i]=max(fr[i],fr[j]+1);
    int mx=0;
    for (int i = 1; i <= n; i++)
        mx=max(mx,fl[i]+fr[i]);
    mx--;
    cout <<n-mx;
    return 0;
}