//Date:
//OJ:
//Problem:
//Solution: 
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
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
#ifdef _DEBUG
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif

return 0;
}
