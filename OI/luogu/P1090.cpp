#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int main()
{
	freopen("in.txt","r",stdin);
	int i,n,sum=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=1;i<n;i++)
	{
		a[i]+=a[i-1];
		sum+=a[i-1];
	}
	cout<<sum;
	return 0;
}
