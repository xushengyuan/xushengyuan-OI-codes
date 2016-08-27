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
		if(son+1<=right && a[son] < a[son+1])
			son++;
		if(a[dad]< a[son])
			return ;
		else
		{
			swap(a[dad],a[son]);
			dad=son;
			son=dad *2+1;
		}
	}
	return ;
}
int len;
int tot;
void set_heap()
{
	int i;
	for(i=len/2-1;i>=0;i--)
		min_heapify(i,len-1);
	return ;
}
int pop_heap()
{
	int temp;
	temp=a[0];
	swap(a[0],a[tot]);
	min_heapify(0,tot-1);
	tot--;
	return temp;
}
void pr()
{
	int j;
	cout<<tot+1<<'-';
	for(j=0;j<len;j++)
		cout<<a[j]<<' ';
	cout<<endl;
	return ;
}
int main()
{
	freopen("in.txt","r",stdin);
	int i,n,sum=0,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	len=n;
	tot=len-1;
	set_heap();
	int num1,mun2;
	pr();
	for(i=0;i<n;i++)
	{
		cout<<pop_heap()<<endl;
		pr();
	}
	cout<<sum;
	return 0;
}
