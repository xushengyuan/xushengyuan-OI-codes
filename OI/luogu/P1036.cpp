#include<iostream>
#include<algorithm>
using namespace std;
int a[25],v[25],list[500000],sum=0,n,k,flag;
int isp(int n)
{
	int i;
	if(n==0||n==1)	return 0;
	if(n==2)	return 1;
	for(i=2;i*i<=n;i++)
		if(n%i==0)	return 0;
	return 1;
}
int dfs(int deep,int num,int p)
{
	int i;
	num+=a[p];
	if(deep>=k)
	{
		if(isp(num))	
		{
			flag=1;
			for(i=0;i<sum;i++)
				if(list[i]==num)
				{
					flag=0;
				}
			if(flag==1)
			{
				list[sum]=num;
				sum++;
			}
		}
		return 0;
	}
	else
	{
		for(i=0;i<n;i++)
			if(v[i]==0)
			{
				v[i]=1;
				dfs(deep+1,num,i);
				v[i]=0;
			}
	}		
	return 0;
}
int main()
{
	int i;
	fill(&v[0],&v[n],0);
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		v[i]=1;
		dfs(1,0,i);
		v[i]=0;
	}	
	cout<<sum;
	return 0;
}
