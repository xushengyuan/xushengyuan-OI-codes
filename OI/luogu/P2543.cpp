//Date:2018/3/19
//OJ:luogu
//Problem:2543
//Solution:LCS DP
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10000
using namespace std;
int f[2][MAXN];
string a,b;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(f,0,sizeof(f));
    cin>>a>>b;
    int lena=a.length(),lenb=b.length();
    int p=0;
    for(int i=1;i<=lena;i++)   
    {
        p=p^1;
        for(int j=1;j<=lenb;j++)
        {
            f[p][j]=(a[i-1]==b[j-1])?f[p^1][j-1]+1:max(f[p^1][j],f[p][j-1]);
            //cout<<f[p][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<f[p][lenb];
    return 0;
}