#include <iostream>  //高精度除法    
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory.h>
using namespace std;
int a[100],c[100],la,lc,x=0,b;
string s1;
void init(){   //初始化是数据
	cin>>s1;  cin>>b;
	memset(a,0,sizeof(a));  memset(c,0,sizeof(c));
	la=s1.size();   //如果在定义是使用char 这里应该是la=strlen(s1)
	for(int i=1;i<=la;i++)  a[i]=s1[la-i]-48;
		//for(int i=i;i<=la;i++)  cout<<a[i];
	return ;
	}
void chufa()
{  //除法，核心代码
	for(int i=la;i>=1;i--)
	{  
        c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	lc=la;
	while(c[lc]==0&&lc>1) lc--;  //删除前导0
	return ;
}
void print(){   //输出
 	for(int i=lc; i>=1; i--)  cout<<c[i];	
	cout<<endl;
	return ;
	}
int main(){
	init();
	chufa();
	print();
	return 0;
	}