#include <bits/stdc++.h>
#define MAXN 400000
#define MAXM 400000
using namespace std;
int in[MAXN]={0},out[MAXN]={0},sum[MAXN]={0};
vector<int> _map[MAXN];
queue<int> q;
int n,m;
int main()
{
	//freopen("in.txt","r",stdin);
	cin >>n>>m;
	int v,u;
	for(int i=1;i<=m;i++)
	{
		cin >>v>>u;
		_map[v].push_back(u);
		in[u]++;
		out[v]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(in[i]==0)
		{
			q.push(i);
			sum[i]=1;
		}
	}
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<_map[p].size();i++)
		{
			in[_map[p][i]]--;
			sum[_map[p][i]]=sum[p]+1;
			if(in[_map[p][i]]==0)
				q.push(_map[p][i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout <<sum[i]<<endl;
	}
	return 0;
}
