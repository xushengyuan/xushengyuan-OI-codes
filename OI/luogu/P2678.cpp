#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;
int l,n,m;
int data[MAXN];
struct stone
{
	int f,b;	
};
stone stones[MAXN];
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
bool judge(int min_dis)
{
	int result=0,sum=0,tmp[MAXN];
	for(int j=0;j<=n+1;j++)
		tmp[j]=stones[j].f;
	for(int i=1;i<=n+1;i++)
	{
		//cout <<tmp[i]<<"|"<<endl;
		if(tmp[i]<min_dis)
		{
			sum++;
			tmp[i+1]+=tmp[i];
		}
	}
	//cout <<sum<<"*"<<endl;
	if(sum>m)
		return false;
	else
		return true;
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)
		data[i]=read_int();
	data[0]=0;
	data[n+1]=l;
	for(int i=1;i<=n+1;i++)
		stones[i].f=data[i]-data[i-1];
	int right,left,mid,tmp;
	left=1;
	right=l;
	while(left<=right)
	{
		mid=(left+right)/2;
		//cout <<left<<' '<<mid<<' '<<right<<endl;
		if(judge(mid))
		{
			tmp=mid;
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	cout <<tmp;
	return 0;
}
