#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char a[100];
int main()
{
	int i,len,n;
	cin>>n;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
			a[i]='a'+(a[i]-'a'+n)%26;
	printf("%s",a);
	return 0;
}
