// #include<bits/stdc++.h>
// #define MAXN 1000100
// using namespace std;
// struct point
// {
// 	int left,right,num,weight,re,pos;
// }tree[MAXN];
// int m,root,result,tree_size;
// void l_r(int &x)
// {
// 	int xr=tree[x].right;
// 	tree[x].right=tree[xr].left;
// 	tree[xr].left=x;
// 	tree[xr].pos=tree[x].pos;
// 	tree[x].pos=tree[tree[x].right].pos+tree[tree[x].left].pos+tree[x].re;
// 	x=xr;
// }
// void r_r(int &x)
// {
// 	int xl=tree[x].left;
// 	tree[x].left=tree[xl].right;
// 	tree[xl].right=x;
// 	tree[xl].pos=tree[x].pos;
// 	tree[x].pos=tree[tree[x].right].pos+tree[tree[x].left].pos+tree[x].re;
// }
// void ins(int &x,int n)
// {
// 	if(x==0)
// 	{
// 		tree_size++;
// 		tree[tree_size].re=1;
// 		tree[tree_size].num=n;
// 		tree[tree_size].weight=rand();
// 		return ;
// 	}
// 	else
// 	{
// 		tree[x]++;
// 		if(tree[x].num==x)
// 			tree[x].re++;
// 		else if(n>tree[x].num)
// 		{
// 			ins(tree[x].right,n);
// 			if(tree[tree[x].right].weight<tree[x].weight)
// 				l_r(x);
// 		}
// 		else
// 		{
// 			ins(tree[x].left,n);
// 			if(tree[tree[x].left].weight<tree[x].weight)
// 				r_r(x);
// 		}
// 	}
// }
// int del(int )
// int main()
// {
// 	return 0;
// }
//Date:2018/3/31
//OJ:luogu
//Problem:3369
//Solution:Treap
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
struct node
{
	Node *ch[2];
	int r, v;
	int cmp(int x) const
	{
		if (x == v)
			return -1;
		return x < v ? 0 : 1;
	}
	void maintain()
	{
		s = ch[0]->s + ch[1]->s + 1;
	}
};
Node *null = new Node();
void rotate(Note *&o, int d)
{
	Node *k = o->ch[d ^ 1];
	o->ch[d ^ 1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
	return;
}
void insert(Node *&o, int x)
{
	if (o == null)
	{
		o = new Node();
		o->ch[0] = null;
		o->ch[1] = null;
		o->v = x;
		o->x = rand();
	}
	else
	{
		int d = o->cmp(x);
		insert(0->ch[d], x);
		if (o->ch[d]->r > o->r)
			rotate(o, d ^ 1);
	}
	return;
}
void remove(Node *&o, int x)
{
	int d = o->cmp(x);
	if (d == -1)
	{
		if (o->ch[0] == null)
			o = o->ch[1];
		else if (o->ch[1] == null)
			o = o->ch[0];
		else
		{
			int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
	}
	else
		remove(o->ch[d],x);
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	return 0;
}