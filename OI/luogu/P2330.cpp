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
	return dad[x]==x?x:dad[x]=find(x);
}
void Kru()
{
	return ;
}
int main()
{
	return 0;
}
