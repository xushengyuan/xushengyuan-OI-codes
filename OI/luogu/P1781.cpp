#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
char a[21][100],b[100];
int main()
{
	freopen("in.txt","r",stdin);
	memset(b,0,100*sizeof(char));
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		if(strlen(a[i])>strlen(b))
			strcpy(b,a[i]);
	}
	puts(b);
	return 0;
}
