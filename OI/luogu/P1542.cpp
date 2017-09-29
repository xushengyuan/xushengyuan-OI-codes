#include <bits/stdc++.h>
#define MAXN 210000
#define ld long double
using namespace std;
int n;
int x[MAXN],y[MAXN],s[MAXN];
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
bool judge(double maxv)
{
	int pt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]/maxv>y[i]-pt)
			return false;
		else
		{
			if(s[i]/maxv<=x[i]-pt)
				pt=x[i];
			else
				pt+=s[i]/maxv;
		}
	}
	return true;
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	int _min=0x7fffffff,_max=-0x7fffffff;
	for(int i=0;i<n;i++)
	{
		x[i]=read_int();
		y[i]=read_int();
		s[i]=read_int();
		//_min=min(y[i]-(i!=0?x[i-1]:0),_min);
		//_max=max(s[i],_max);
	}
	ld left=1e-9,right=1e11;
	//cout<<left<<' '<<right<<endl;
	double mid=(left+right)/2.0;
	while(right-left>1e-9)
	{
		mid=(left+right)/2.0;
		//cout<<mid<<endl;
		if(judge(mid))
			right=mid;
		else
			left=mid;
	}
	//cout<<mid<<endl;
	printf("%.2f",mid);
	return 0;
}
