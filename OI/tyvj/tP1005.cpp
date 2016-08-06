#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,f[1000];
struct thing
{
	int p;
	int v;
}th[102];
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++)
		cin>>th[i].p>>th[i].v;
	for(i=1;i<=m;i++)
        for(j=n;j>=th[i].p;j--)
            f[j] = max ( f[j] , f[j-th[i].p]+th[i].v );
	cout<<f[n];
	return 0;
}

