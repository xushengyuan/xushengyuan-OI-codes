#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
long long c=0,thing[6]= {0},sum=0;
void read(string &a)
{
	if(a=="one" || a=="a" || a=="another" || a=="first")
	{
		thing[c]=1;
		c++;
	}
	else if(a=="two" || a=="both" || a=="second")
	{
		thing[c]=4;
		c++;
	}
	else if(a=="three" || a=="third")
	{
		thing[c]=9;
		c++;
	}
	else if(a=="four")
	{
		thing[c]=16;
		c++;
	}
	else if(a=="five")
	{
		thing[c]=25;
		c++;
	}
	else if(a=="six")
	{
		thing[c]=36;
		c++;
	}
	else if(a=="seven")
	{
		thing[c]=49;
		c++;
	}
	else if(a=="eight")
	{
		thing[c]=64;
		c++;
	}
	else if(a=="nine")
	{
		thing[c]=81;
		c++;
	}
	else if(a=="eleven")
	{
		thing[c]=21;
		c++;
	}
	else if(a=="twelve")
	{
		thing[c]=44;
		c++;
	}
	else if(a=="thirteen")
	{
		thing[c]=69;
		c++;
	}
	else if(a=="forteen")
	{
		thing[c]=96;
		c++;
	}
	else if(a=="fifteen")
	{
		thing[c]=25;
		c++;
	}
	else if(a=="sixteen")
	{
		thing[c]=56;
		c++;
	}
	else if(a=="seventeen")
	{
		thing[c]=89;
		c++;
	}
	else if(a=="eighteen")
	{
		thing[c]=24;
		c++;
	}
	else if(a=="nineteen")
	{
		thing[c]=61;
		c++;
	}
}
int main()
{
	iint i;
	string c2[6];
	for( i=0; i<6; i++)
		cin>>c2[i];
	for( i=0; i<6; i++)
	{
		int j=c2[i].find('.',0);
		if(j>=0)
			c2[i]=c2[i].erase(j,1);
		read(c2[i]);
	}
	sort(thing,thing+c);
	for(int i=0; i<c; i++)
		sum=sum*100+thing[i];
	cout<<sum;
	return 0;
}
