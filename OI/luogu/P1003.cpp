#include<bits/stdc++.h>
#define r(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int n,a[10001],b[10001],c[10001],d[10001],i,j,x,y,k=-1;
int main()
{
	cin>>n;
	r(i,1,n)    cin>>a[i]>>b[i]>>c[i]>>d[i];
	cin>>x>>y;
	for(i=n; i>=1; i--)
		if(a[i]<=x&&x<=a[i]+c[i]&&b[i]<=y&&y<=b[i]+d[i])
		{
			k=i;
			break;
		}
	cout<<k;
	return 0;
}
