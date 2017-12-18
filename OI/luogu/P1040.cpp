//Date: 2017/10/08
//OJ:
//Problem:
//Solution: 
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 55
#define ll long long 
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
ll f[MAXN][MAXN];
int root[MAXN][MAXN];
int num[MAXN],n;
void tree_out(int left,int right)
{
	if(left==right)
	{
		cout<<left<<' ';
		return ;
	}
	int ro=root[left][right];
	cout<<ro<<' ';
	if(ro!=left)
		tree_out(left,ro-1);
	if(ro!=right)
		tree_out(ro+1,right);
	return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)
    {
	   	num[i]=read_int();
	   	f[i][i]=num[i];
	}
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<=j;k++)
			{
				int tmp=(i==k?1:f[i][k-1])*
						(j==k?1:f[k+1][j])+
						num[k];
				if(tmp>f[i][j])
				{
					root[i][j]=k;
					f[i][j]=tmp;	
				}
			}
	/*for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cout<<i<<'-'<<j<<':'<<f[i][j]<<endl;*/
	cout<<f[1][n]<<endl;
	tree_out(1,n);
    return 0;
}
