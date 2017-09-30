#include <bits/stdc++.h>
#define MAXM 410
using namespace std;
int m[MAXM],v[MAXM],f[MAXM][MAXM],w[MAXM];
int n,maxv,maxm;
int main()
{
	cin>>maxv>>maxm>>n;
	for(int i=0;i<n;i++)
		cin>>v[i]>>m[i]>>w[i];
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++)
		for(int vi=maxv;vi>=v[i];vi--)
			for(int mi=maxm;mi>=m[i];mi--)
				f[vi][mi]=max(f[vi][mi],f[vi-v[i]][mi-m[i]]+w[i]);
	cout<<f[maxv][maxm];
	return 0;
}
