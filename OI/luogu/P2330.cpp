#include <bits/stdc++.h>
#define MAXN 310
#define MAXM 50010
using namespace std;
struct node
{
	int u,v;
	int w;
}nodes[MAXM];
int n,m;
int dad[MAXN];
void init()
{
	for(int i=0;i<MAXN;i++)
		dad[i]=i;
	return ;
}
int find(int x)
{
	return dad[x]==x ? x : dad[x]=find(dad[x]);
}
int Kru()
{
	int tot=0,_max=-0x7fffffff;
	for(int i=0;i<m;i++)
	{
		int dadu=find(nodes[i].u),dadv=find(nodes[i].v);
		if(dadu!=dadv)
		{
			tot++;
			_max=max(_max,nodes[i].w);
			dad[dadu]=dadv;
		}
	}	
	return _max;
}
int cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>nodes[i].u>>nodes[i].v>>nodes[i].w;
	sort(nodes,nodes+m,cmp);
	cout<<n-1<<' ';
	cout<<Kru();
	return 0;
}
