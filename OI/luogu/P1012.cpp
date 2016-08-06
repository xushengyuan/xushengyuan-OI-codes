#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
string str[1000];
int c(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	freopen("in.txt","r",stdin);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>str[i];
	sort(str,str+n,c);
	for(i=0;i<n;i++)
		cout<<str[i];
	return 0;
}
