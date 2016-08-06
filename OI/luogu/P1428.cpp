#include<iostream>
using namespace std;
int a[102];
int main()
{
	int n,i,j,sum;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum=0;
		for(j=0;j<i;j++)
			if(a[j]<a[i])
				sum++;
		cout<<sum<<' ';
	}
	return 0;
 } 
