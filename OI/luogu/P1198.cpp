//Date:2018/2/9
//OJ:luogu
//Problem:1198
//Solution:ST table
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 200010
using namespace std;
int m,D;
long long data[MAXN],st[MAXN][21];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(st,0,sizeof(st));
    cin>>m>>D;
    long long n=0,t=0;
    for(int i=1;i<=m;i++)
    {
        char ch;
        long long tmp;
        cin>>ch>>tmp;
        if(ch=='A')
        {
            n++;
            data[n]=(tmp+t)%D;
            st[n][0]=data[n];
            for(int j=1;n>=(1<<j);j++)
                st[n][j]=max(st[n][j-1],st[n-(1<<(j-1))][j-1]);
            //cout<<"t="<<t<<endl;
        }
        else if(ch=='Q')
        {
            int p=(int)(log(tmp)/log(2));
            t=max(st[n][p],st[n-tmp+(1<<p)][p]);
            cout<<t<<endl;
        }
    }
    return 0;
}
