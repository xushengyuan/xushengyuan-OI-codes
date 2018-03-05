//Date:2018/2/22
//OJ:luogu
//Problem:1087
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 50
using namespace std;
int n;
string s;
int tree[MAXN];
void out(int p)
{
    if(p>(2<<n)-1)
        return ;
    else
    {
        out(p*2);
        out(p*2+1);
        if(tree[p]==0)
            cout<<'B';
        else if(tree[p]==1)
            cout<<'I';
        else if(tree[p]==2)
            cout<<'F';
        return;
    }
}
int f(int p,int layer)
{
    if(layer==n+1)
        return tree[p];
    int ls=f(p*2,layer+1);
    int rs=f(p*2+1,layer+1);
    if(ls!=rs)
        tree[p]=2;
    else if(ls==0)
        tree[p]=0;
    else if(ls==1)
        tree[p]=1;
    else if(ls==2)
        tree[p]=2;
    return tree[p];
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++) 
        tree[(2<<n)-1-i]=s[s.size()-i-1]-'0';
    f(1,1);
    out(1);
    return 0;
}