#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[52][52],f[52][52];
int main()
{
	memset(a,0,52*52*sizeof(int));
	memset(f,0,52*52*sizeof(int));
	freopen("in.txt","r",stdin);
	int i,j,k,sum=0;;
	cin>>m>>n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(f[i][j-1]>f[i-1][j])
			{
				f[i][j]=f[i][j-1]+a[i][j];
			}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}
	sum+=f[m][n];
	for(i=m;i>=1;i--)
		for(j=n;j>=1;j--)
			f[i][j]=max(f[i][j+1],f[i+1][j])+a[i][j];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}
	sum+=f[1][1];
	cout<<sum;
	return 0;
}

