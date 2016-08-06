#include<iostream>

using namespace std;
int num[102];
int main()
{
	int i=0,j;
	cin>>num[0];
	while(num[i]!=0)
	{
		i++;
		cin>>num[i];
	}
	for(j=i-1;j>=0;j--)
		cout<<num[j]<<' ';
	return 0;
 } 
