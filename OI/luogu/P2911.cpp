#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int data[MAXN]={0};
int main()
{
	int s1,s2,s3;
	cin >>s1>>s2>>s3;
	for(int a1=1;a1<=s1;a1++)
		for(int a2=1;a2<=s2;a2++)
			for(int a3=1;a3<=s3;a3++)
				data[a1+a2+a3]++;
	int mx=-0x7fffffff,mxn;
	for(int i=1;i<=MAXN;i++)
		if(data[i]>mx)
		{
			mx=data[i];
			mxn=i;
		}
	cout <<mxn;
	return 0;
}
