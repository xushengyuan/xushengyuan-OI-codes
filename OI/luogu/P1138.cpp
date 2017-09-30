#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int data[10010];
	for(int i=0;i<n;i++)
		cin>>data[i];
	sort(data,data+n);
	int t=1;
	for(int i=1;i<n;i++)
	{
		if(data[i]!=data[i-1])
			t++;
		if(t==k)
		{
			cout<<data[i];
			exit(0);
		}
	}
	cout<<"NO RESULT";
	return 0;
}
