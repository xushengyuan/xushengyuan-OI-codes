#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int n,m,s,t;
vector<int> rv_map[MAXN];
bool con[MAXN];
void pre_bfs(int sou)
{
	queue<int> q;
	q.push(sou);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		con[p]=true;
		for(int i=0;i<rv_map[p].size();i++)
			q.push(rv_map[p][i]);
	}
	return ;
}
int main()
{
	cin>>n>>m;
	int tx,ty;
	for(int i=0;i<m;i++)
	{
		cin>>tx>>ty;
		tx--,ty--;
		rv_map[ty].push_back(tx);
	}
	cin>>s>>t;
	memset(con,0,sizeof(con));
	pre_bfs(t);
	for(int i=0;i<n;i++)
		cout <<con[i]<<endl;
}
