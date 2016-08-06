#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#Include<cstdio>
using namespace std;
struct BigInteger
{
	static const int maxn = 1000;
	static const int maxval = 10000;
	int top;
	int numb[maxn];
	BigInteger()
	{
		top=0;
		memset(numb,0,sizeof(numb));
	}
	BigInteger(string str)
	{
		memset(numb,0,sizeof(numb));
		top=(str.length()-1)/4;
		for (int i=0; i<str.length(); i++)
			numb[(str.length()-i-1)/4]=numb[(str.length()-i-1)/4]*10+str[i]-'0';
	}
	void Read()
	{
		string str;
		cin>>str;
		(*this) = BigInteger(str);
	}
	void Print()
	{
		printf("%d",numb[top]);
		for (int i=top-1; i>=0; i--)
			printf("%04d",numb[i]);
		printf("\n");
	}
	void Print_detail()
	{
		cout<<"TOP:"<<top<<endl;
		cout<<"{";
		for (int i=0; i<=top; i++)
		{
			printf("%04d",numb[i]);
			cout<<",";
		}
		cout<<"}"<<endl;
	}
};
istream & operator >> (istream &in,BigInteger& num)
{
	string str;
	in>>str;
	num = BigInteger(str);
	return in;
}
ostream & operator << (ostream &out,BigInteger &num)
{
	char buf[10];
	out<<num.numb[num.top];
	for (int i=num.top-1; i>=0; i--)
	{
		sprintf(buf,"%04d",num.numb[i]);
		out<<buf;
	}
	return out;
}

BigInteger operator +(BigInteger &num1,BigInteger &num2)
{
	BigInteger ret;
	ret.top=max(num1.top,num2.top);
	for (int i=0; i<=ret.top; i++)
	{
		ret.numb[i] = (ret.numb[i] + num1.numb[i] + num2.numb[i]);
		if (ret.numb[i]>=BigInteger::maxval)
			ret.numb[i]-=BigInteger::maxval,ret.numb[i+1]++;
	}
	if (ret.numb[ret.top+1])ret.top++;
	return ret;
}

BigInteger operator *(BigInteger &num1,BigInteger &num2)
{
	BigInteger ret;
	ret.top = num1.top + num2.top;
	for (int i=0; i<=num1.top; i++)
		for (int j=0; j<=num2.top; j++)
		{
			ret.numb[i+j] += num1.numb[i] * num2.numb[j];
			ret.numb[i+j+1] += ret.numb[i+j]/BigInteger::maxval;
			ret.numb[i+j] %= BigInteger::maxval;

		}
	for (int i=0; i<=ret.top; i++)
	{
		ret.numb[i+1] += ret.numb[i]/BigInteger::maxval;
		ret.numb[i] %= BigInteger::maxval;
	}
	if (ret.numb[ret.top+1])ret.top++;
	return ret;
}
int Mod(BigInteger &num1,int p)
{
	int ret=0;
	for (int i=num1.top; i>=0; i--)
		ret = (ret*BigInteger::maxval + num1.numb[i])%p;
	return ret;
}

BigInteger get(int n,BigInteger a)
	{
		BigInteger str;
		if(n%4==0)
			str.numb[0]=a.numb[n/4]/1000;
		if(n%4==1)
			str.numb[0]=a.numb[n/4]/100%10;
		if(n%4==2)
			str.numb[0]=a.numb[n/4]/10%10;
		if(n%4==3)
			str.numb[0]=a.numb[n/4]%10;
		str.top=1;
		return str;
	}

BigInteger btod()
{
	int i;
	BigInteger sum,two("1");
	scanf("")
	char tt[50];
	for(i=0; i<; i++)
	{
		
	}
	return sum;
}
void dtob(BigInteger str)
{
	while(str.top>0)
	{

	}
}
int main()
{
	BigInteger A;
	//freopen("conv.in","r",stdin);
	//freopen("conv.out","w",stdout);
	int flag;
	cin>>flag;
	cin>>A;
	E(50).Print_detail();
	A.Print_detail();
	get(6,A).Print();
	return 0;
}
