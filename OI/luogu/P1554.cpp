//Date:2018/8/3
//OJ:luogu
//Problem:1554
//Solution:String
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n,m;
char str[12];
int cot[10];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    memset(cot,0,sizeof(cot));
    for(int i=n;i<=m;i++)
    {
        int len=sprintf(str,"%d",i);
        for(int j=0;j<len;j++)
            cot[str[j]-'0']++;
    }
    for(int i=0;i<10;i++)
        cout<<cot[i]<<' ';
    cout<<endl;
    return 0;
}