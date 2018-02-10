//Date:2018/2/9
//OJ:luogu
//Problem:2676
//Solution:qsort
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 20010
#define _DEBUG
using namespace std;
int n,h;
int data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>h;
    for (int i = 0; i < n; i++)
        cin>>data[i];
    sort(data,data+n,greater<int>());
    int sum=0,tot=0;
    while(sum<h)
        sum+=data[tot++];
    cout<<tot<<endl;
}

    
    
    