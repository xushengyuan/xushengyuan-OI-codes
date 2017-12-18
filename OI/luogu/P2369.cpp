//Date:2017/10/8	
//OJ:luogu
//Problem:2369
//Solution: Qsort
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000100
using namespace std;
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
int data[MAXN];
int m,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++)
    	data[i]=read_int();
    sort(data,data+n);
    for(int i=0;i<m;i++)
    	cout<<data[i]<<endl;
    return 0;
}
