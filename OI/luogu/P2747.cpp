#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
bool _map[MAXN][MAXN];
int f[MAXN][MAXN];
map<string,int> mp;
int n,m;
int main()
{
	//freopen("in.txt","r",stdin);
	memset(_map,0,sizeof(_map));
	cin>>n>>m;
	string tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		mp[tmp]=i;		
	}
	string tmp1,tmp2;
	for(int i=0;i<m;i++)
	{
		cin>>tmp1>>tmp2;
		_map[mp[tmp1]][mp[tmp2]]=true;
		_map[mp[tmp2]][mp[tmp1]]=true;
	}
	memset(f,0,sizeof(f));
	f[0][0]=1;
	int t;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<j;k++)
				if(_map[j][k] && f[i][k]!=0)
					f[i][j]=max(f[i][j],f[i][k]+1);
			f[j][i]=f[i][j];
		}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<f[i][j]<<' ';
		cout <<endl;
	}*/
	int result=1;
	for(int i=0;i<n;i++)
	{
		if(_map[i][n-1])
			result=max(result,f[i][n-1]);
	}
	cout <<result;
	return 0;
}
