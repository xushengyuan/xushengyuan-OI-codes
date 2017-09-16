#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;
int data[MAXN][MAXN],sum[MAXN][MAXN]={0};
int t,k;
int read_int()
{
	int result=0;
	char t;
	t=getchar();
	while(!isdigit(t))
		t=getchar();
	while(isdigit(t))
	{
		result=result*10+t-'0';
		t=getchar();
	}
	return result;
}
void init()
{
	memset(data,0,sizeof(data));
	memset(sum,0,sizeof(sum));
	data[1][1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		for(int j=1;j<=i;j++)
		{
			data[i][j]=(data[i-1][j]+data[i-1][j-1])%k;
			if(data[i][j]==0)
				sum[i][j]=sum[i][j-1]+1;
			else
				sum[i][j]=sum[i][j-1];
		}
	}
	return ;
}
int main()
{
	cin >>t>>k;
	int temp=t,tmp=k;
	init();
	int m,n,result=0;
	t=temp;
	k=tmp;
	for(int i=0;i<t;i++)
	{
		n=read_int();
		m=read_int();
		for(int a=0;a<=n;a++)
			result+=sum[a+1][min(a,m)+1];
		cout <<result<<endl;
		result=0;
	}
	return 0;
}
