#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int exgcd(int a,int b,int &x,int &y)//ax+by == gcd(a,b)
{
	if (a%b==0)//gcd(a,b) == b
	{
		//ax+by == b
		x=0;
		y=1;
		printf(">>a=%d,b=%d,x=%d,y=%d\n",a,b,x,y);
		return b;
	}
	int tx,ty,ret;
	ret = exgcd(b,a%b,tx,ty);
	x=ty;
	y=tx-a/b*ty;
	printf(">>a=%d,b=%d,x=%d,y=%d\n",a,b,x,y);
	return ret;
}
int main()
{
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	printf("a=%d,b=%d,x=%d,y=%d\n",a,b,x,y);
	printf("ax+by=%d\n",a*x+b*y);
}
