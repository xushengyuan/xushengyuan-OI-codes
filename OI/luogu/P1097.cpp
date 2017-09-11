#include <bits/stdc++.h>
#define MAXN 20010
using namespace std;
int data[MAXN];
int n;
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
int main()
{
	//freopen("in.txt","r",stdin);
	cin >>n;
	for(int i=0;i<n;i++)
		data[i]=read_int();
	sort(data,data+n);
	int t=data[0],ans=1;
	for(int i=1;i<n;i++)
	{
		//cout <<'|'<<data[i]<<endl;
		if(data[i]==t)
		{
			ans++;
		}
		else
		{
			cout <<t<<' '<<ans<<endl;
			ans=1;
			t=data[i];
		}
	}
	cout <<t<<' '<<ans<<endl;
	return 0;
}
