#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,sum=0,t;
	cin >>n>>k;
	sum+=n;
	while(n>=k)
	{
		t=n/k;
		sum+=t;
		n%=k;
		n+=t;
	}
	cout <<sum;
	return 0;
}
