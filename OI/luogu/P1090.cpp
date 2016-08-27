#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];

void min_heapify(int left,int right)
{
	int dad,son;
	dad=left;
	son=dad*2+1;
	while(son<=right)
	{
		if(son+1<=end && a[son] < a[son+1])
			son++;
		if(a[dad]< srr[son])
			return ;
		else
		{
			swap(a[dad],a[son]);
			dad=son;
			son=dad *+1;
		}
	}
	return ;
}
void pop_heap()
{
	int i;
	for(i=len/2-1;i>=;i--)
		max_heapify(i,len-1);
	
}
int main()
{
	freopen("in.txt","r",stdin);
	int i,n,sum=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	int min1=20000000,min2=20000000,mn1,mn2;
	for(i=0;i<n;i++)
	{
		
	}
	cout<<sum;
	return 0;
}
