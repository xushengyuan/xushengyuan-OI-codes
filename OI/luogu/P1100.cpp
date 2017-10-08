//Date:2017/10/8
//OJ:luogu
//Problem:1100
//Solution: None
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,result;
	cin>>n;
	result=n>>16;
	result=result|((n&0x0000FFFF)<<16);
	cout<<result;
}
