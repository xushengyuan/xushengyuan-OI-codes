//Date:2017/8/9
//OJ:luogu
//Problem:1025
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 210
using namespace std;
int a[8];
int n,k,result=0;
void dfs(int rem,int p)
{
    if(p==k)
    {
        result++;
        /*for(int i=1;i<=p;i++)
            cout <<a[i]<<' ';
        cout <<endl;*/
        return ;
    }
    for(int i=a[p-1];i<=rem/(k-p+1);i++)
    {
        a[p]=i;
        dfs(rem-i,p+1);
    }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>k;
    a[0]=1;
    dfs(n,1);
    cout <<result;
    return 0;
}