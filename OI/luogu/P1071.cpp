#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
string a,b,c;
char s[26];
bool ss[26];
bool is()
{
	if(a.length()<26) return false;
	int i;
	for(i=0;i<a.length();i++)
	{
		if(s[a.at(i)-'A']==' ')
		{
			if(ss[b.at(i-'A')]==true)
				return false;
			s[a.at(i)-'A']=b.at(i);
			ss[b.at(i)-'A']=true;
		}
		else if(b.at(i)!=s[a.at(i)] )
			return false;
	}
	return true;
}
int main()
{
	freopen("in.txt","r",stdin);
	memset(s,' ',26*sizeof(char));
	fill(ss,ss+26,false);
	cin>>a;
	cin>>b;
	cin>>c;
	if(is())
	{
		;
	}
	else
		cout<<"Failed";
	return 0;
}

