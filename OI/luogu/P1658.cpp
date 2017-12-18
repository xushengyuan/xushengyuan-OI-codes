//Date:2017/10/8	
//OJ:luogu
//Problem:1658
//Solution: Ì°ÐÄ 
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 10
using namespace std;
int data[MAXN];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int x,n;
    cin>>x>>n;
    for(int i=0;i<n;i++)
    	cin>>data[i];
    sort(data,data+n);
    if(data[0]!=1)
    {
    	cout<<-1;
    	exit(0);
	}
    int sum=0,ans=0;
    while(sum<x)
    {
    	int t=n-1;
    	while(data[t]>(sum+1))
    		t--;
    	sum+=data[t];
    	ans++;
	}
	cout<<ans;
    return 0;
}
