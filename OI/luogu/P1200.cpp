#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char a[7],b[7];
int main()
{
	int i,sum1=1,sum2=1,len1,len2;
	scanf("%s%s",a,b);
	len1=strlen(a);
	len2=strlen(b);
	for(i=0;i<len1;i++)
		sum1*=a[i]-'A'+1;
	for(i=0;i<len2;i++)
		sum2*=b[i]-'A'+1;
	if(sum1%47 == sum2%47)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
}
