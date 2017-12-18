#include<bits/stdc++.h> 
#define MAXN 1000100
using namespace std;
struct point
{
	int left,right,num,weight,re,pos;
}tree[MAXN];
int m,root,result,tree_size;
void l_r(int &x) 
{
	int xr=tree[x].right;
	tree[x].right=tree[xr].left;
	tree[xr].left=x;
	tree[xr].pos=tree[x].pos;
	tree[x].pos=tree[tree[x].right].pos+tree[tree[x].left].pos+tree[x].re;
	x=xr;
}
void r_r(int &x)
{
	int xl=tree[x].left;
	tree[x].left=tree[xl].right;
	tree[xl].right=x;
	tree[xl].pos=tree[x].pos;
	tree[x].pos=tree[tree[x].right].pos+tree[tree[x].left].pos+tree[x].re;
}
void ins(int &x,int n)
{
	if(x==0)
	{
		tree_size++;
		tree[tree_size].re=1;
		tree[tree_size].num=n;
		tree[tree_size].weight=rand();
		return ;
	}
	else
	{
		tree[x]++;
		if(tree[x].num==x)
			tree[x].re++;
		else if(n>tree[x].num)
		{
			ins(tree[x].right,n);
			if(tree[tree[x].right].weight<tree[x].weight)
				l_r(x);
		}
		else
		{
			ins(tree[x].left,n);
			if(tree[tree[x].left].weight<tree[x].weight)
				r_r(x);
		}
	}
}
int del(int )
int main()
{
	return 0;
}
