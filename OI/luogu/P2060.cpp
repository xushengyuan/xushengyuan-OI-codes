#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n=n*2+1;
	int num=1,result=1;
	num=num*2%n;
	while(num!=1)
	{
		num=num*2%n;
		result++;
	}
	cout <<result;
	return 0;
}
