#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	long int i,x,n,sum=0;
	cin >>x>>n;
	for(i=0;i<n;i++)
	{
		if(x!=6 && x!=7)
		{
			sum+=250;
		}
		if(x!=7)
		{
			x++;
		}
		else
		{
			x=1;
		}
	}
	cout <<sum;
}
