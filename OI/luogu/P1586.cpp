//Date:2017/9/26
//OJ:luogu
//Problem:1586
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 185
using namespace std;
int n;
int sum[5][32769];
void init()
{
	memset(sum,0,sizeof(sum));
	sum[0][0]=1;
	for(int i=1;i*i<=32768;i++)
		for(int len=1;len<=4;len++)
			for(int j=i*i;j<=32768;j++)
				sum[len][j]+=sum[len-1][j-i*i];
	return ;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	init();
	//for(int i=0;i<1000;i++)
	//	cout <<sum[i]<<' ';
	for(int t=0;t<n;t++)
	{
		int tmp;
		cin>>tmp;
		cout <<sum[1][tmp]+sum[2][tmp]+sum[3][tmp]+sum[4][tmp]<<endl;

	}
	return 0;
}
