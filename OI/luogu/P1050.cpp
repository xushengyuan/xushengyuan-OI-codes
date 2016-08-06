#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cctype>
using namespace std;
char a[15];
int main()
{
	int i,sum=0,j=1;
	scanf("%s",a);
	for(i=0;i<12;i++)
		if(isdigit(a[i]))
		{
			sum+=(a[i]-'0')*j;
			j++;
		}
	if(sum%11==0 && a[12]=='X')
		cout<<"Right";
	else if(sum%11 == a[12]-'0')
		cout<<"Right";
	else
	{
		for(i=0;i<12;i++)
			cout<<a[i];
		cout<<sum%11;
	}
}
