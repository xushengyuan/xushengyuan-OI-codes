#include <iostream>
using namespace std;
static char ans[256];
char inline trans(int x)
{
	return (x < 10) ? (x + '0') : (x - 10 + 'A');
}
int main()
{
	int x, s, k, i = 0;
	cin>>x>>k;
	cout<<x<<'=';
	while (x)
	{
		int mod = x % k;
		mod = (mod < 0) ? (mod - k) : mod;
		ans[i++] = trans(mod);
		x = (x - mod) / k;
	}
	while (i--) 
		cout<<ans[i];
	cout<<"(base"<<k<<')';
	return 0;
}
