//Date:2017/8/19
//OJ:luogu
//Problem:1967
//Solution:Kruskal LCA
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 10100
#define MAXM 50100
using namespace std;
vector<pair<int,int> > _map[MAXN];
struct edge
{
	int u;
	int v;
	int w;
}edges[MAXM];
int n,m;
int dad[MAXN];
void init_uni()
{
	for(int i=0;i<n;i++)
		dad[i]=i;
}
int lca(int a,int b)
{
	int _min=0x7fffffff;
	
	return _min;
}
int find(int p)
{
	return dad[p]==p?p:dad[p]=find(dad[p]);
}
void kru()
{
	int sum=0;
	init_uni();
	for(int i=0;i<m;i++)
	{
		int dad_u=find(edges[i].u),dad_v=find(edges[i].v);
		if(dad_u == dad_v)
			continue;
		sum++;
		dad[dad_u]=dad_v;
		add_edge(edges[i].u,edges[i].v,edges[i].w);
		if(sum>=n-1)
			return ;
	}
	return ;
}
void add_edge(int u,int v,int w)
{
	_map[u].push_back({v,w});
	_map[v].push_back({u,w});
	return ;
}
int read_int()
{
	int result=0;
	char t;
	t=getchar();
	while(!isdigit(t))
		t=getchar();
	while(isdigit(t))
	{
		result=result*10+'0';
		t=getchar();
	}
	return result;
}
void dfs(int p)
{
	
}
bool cmp(edge a,edge b)
{
	return a.w>b.w;
}
int main()
{
	freopen("in.txt","r",stdin);
	cin >>n>>m;
	for(int i=0;i<m;i++)
	{
		edges[i].u=read_int();
		edges[i].v=read_int();
		edges[i].w=read_int();
	}
	sort(edges,edges+m,cmp);
	kru();
	return 0;
}