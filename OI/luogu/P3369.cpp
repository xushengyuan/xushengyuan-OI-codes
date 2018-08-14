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
// #include <bits/stdc++.h>
// #define _DEBUG
// #define INF 0x3fffffff
// #define MAXN 500100
// using namespace std;
// struct Node
// {
// 	Node *ch[2];
// 	int r, v, s=1;
// 	int cmp(int x) const
// 	{
// 		if (x == v)
// 			return -1;
// 		return x < v ? 0 : 1;
// 	}
// 	void maintain()
// 	{
// 		s = 1;
// 		if (ch[0] != NULL)
// 			s += ch[0]->s;
// 		if (ch[1] != NULL)
// 			s += ch[1]->s;
// 	}
// };
// //Node *NULL = new Node();
// void rotate(Node *&o, int d)
// {
// 	Node *k = o->ch[d ^ 1];
// 	o->ch[d ^ 1] = k->ch[d];
// 	k->ch[d] = o;
// 	o->maintain();
// 	k->maintain();
// 	o = k;
// 	return;
// }
// void insert(Node *&o, int x)
// {
// 	if (o == NULL)
// 	{
// 		o = new Node();
// 		o->ch[0] = NULL;
// 		o->ch[1] = NULL;
// 		o->v = x;
// 		o->r = rand();
// 	}
// 	else
// 	{
// 		int d = (o->cmp(x)==-1?0:o->cmp(x));
// 		insert(o->ch[d], x);
// 		if (o->ch[d]->r > o->r)
// 			rotate(o, d ^ 1);
// 		o->maintain();
// 	}
// 	return;
// }
// void remove(Node *&o, int x)
// {
// 	int d = o->cmp(x);
// 	if (d == -1)
// 	{
// 		if (o->ch[0] == NULL)
// 			o = o->ch[1];
// 		else if (o->ch[1] == NULL)
// 			o = o->ch[0];
// 		else
// 		{
// 			int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
// 			rotate(o, d2);
// 			remove(o->ch[d2], x);
// 		}
// 	}
// 	else
// 		remove(o->ch[d], x);
// 	if (o != NULL)
// 		o->maintain();
// }
// int kth(Node *o, int k)
// {
// 	if ((o->ch[0] != NULL?o->ch[0]->s:0) == k - 1)
// 		return o->v;
// 	else if ((o->ch[0] != NULL?o->ch[0]->s:0) >= k)
// 		return kth(o->ch[0], k);
// 	else if(o->ch[1] != NULL)
// 		return kth(o->ch[1], k - (o->ch[0]!=NULL?o->ch[0]->s:0) - 1);
// }
// int Rank(Node *o, int x)
// {
// 	if (o == NULL)
// 		return 1;
// 	if (o->v >= x)
// 		return Rank(o->ch[0], x);
// 	else
// 		return Rank(o->ch[1], x) + (o->ch[0] != NULL ? o->ch[0]->s : 0) + 1;
// }
// int pre(Node *o, int x)
// {
// 	if (o == NULL)
// 		return -INF;
// 	else if (o->v < x)
// 		return max(pre(o->ch[1], x), o->v);
// 	else
// 		return pre(o->ch[0], x);
// }
// int nex(Node *o, int x)
// {
// 	if (o == NULL)
// 		return INF;
// 	if (o->v > x)
// 		return min(nex(o->ch[0], x), o->v);
// 	else
// 		return nex(o->ch[1], x);
// }
// int read_int()
// {
// 	int result = 0;
// 	char t = getchar();
// 	while (!isdigit(t))
// 		t = getchar();
// 	while (isdigit(t))
// 	{
// 		result = result * 10 + t - '0';
// 		t = getchar();
// 	}
// 	return result;
// }
// Node *root=NULL;
// int main()
// {
// #ifdef _DEBUG
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// #endif
// 	int n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if(root!=NULL)
// 		{
// 			root->maintain();
// 			//out<<root->s<<endl;
// 		}
// 		int opt = read_int(), x = read_int();
// 		switch (opt)
// 		{
// 		case 1:
// 			insert(root, x);
// 			break;
// 		case 2:
// 			remove(root, x);
// 			break;
// 		case 3:
// 			printf("%d\n", Rank(root, x));
// 			break;
// 		case 4:
// 			printf("%d\n", kth(root, x));
// 			break;
// 		case 5:
// 			printf("%d\n", pre(root, x));
// 			break;
// 		case 6:
// 			int tmp=nex(root, x);
// 			printf("%d\n", tmp);
// 			break;

// 		}
// 	}
// 	return 0;
// }
//Date:2018/8/13
//OJ:luogu
//Problem:3369
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define INF 0x3fffffff
#define MAXN 100000
using namespace std;
int size[MAXN],ch[MAXN][2],v[MAXN],r[MAXN];
int n=0;
void maintain(int p)
{
	size[p]=size[ch[p][0]]+size[ch[p][1]]+1;
}
void rotate(int &p,int d)
{
	int tmp=ch[p][d];
	ch[p][d]=ch[tmp][d^1];
	ch[tmp][d^1]=p;
	maintain(p);
	maintain(tmp);
	p=tmp;
}
void insert(int &p,int x)
{
	if(p==0)
	{
		p=++n;
		size[p]=1;
		v[p]=x;
		r[p]=rand();
		return;
	}
	size[p]++;
	if(x<=v[p])
	{
		insert(ch[p][0],x);
		if(r[ch[p][0]]<r[p])
			rotate(p,0);
	}
	else
	{
		insert(ch[p][1],x);
		if(r[ch[p][1]]<r[p])
			rotate(p,1);
	}
}
void remove(int &p,int x)
{
	if(v[p]==x)
	{
		if(ch[p][0]==0 || ch[p][1]==0)
		{
			p=ch[p][0]+ch[p][1];
			return ;
		}
		if(r[ch[p][0]]>r[ch[p][1]])
		{
			rotate(p,1);
			remove(ch[p][0],x);
		}
		else
		{
			rotate(p,0);
			remove(ch[p][1],x);
		}
	}
	else if(v[p]>x)
		remove(ch[p][0],x);
	else
		remove(ch[p][1],x);
	maintain(p);
	return ;
}
int Rank(int p,int x)
{
	if(p==0)
		return 1;
	if(v[p]>=x)
		return Rank(ch[p][0],x);
	else
		return Rank(ch[p][1],x)+size[ch[p][0]]+1;
}
int kth(int p,int k)
{
	if(size[ch[p][0]]==k-1)
		return v[p];
	if(size[ch[p][0]]>=k)
		return kth(ch[p][0],k);
	else
		return kth(ch[p][1],k-size[ch[p][0]]-1);
}
int pre(int p,int x)
{
	if(p==0)
		return -INF;
	if(v[p]<x)
		return max(v[p],pre(ch[p][1],x));
	else
		return pre(ch[p][0],x);
}
int nex(int p,int x)
{
	if(p==0)
		return INF;
	if(v[p]>x)
		return min(v[p],nex(ch[p][0],x));
	else
		return nex(ch[p][1],x);
}
int read_int()
{
	int result = 0;
	char t = getchar();
	while (!isdigit(t))
		t = getchar();
	while (isdigit(t))
	{
		result = result * 10 + t - '0';
		t = getchar();
	}
	return result;
}
int main()
{
	#ifdef _DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int m,root=0;
	cin>>m;
	for (int i = 0; i < m; i++)
	{
 		int opt = read_int(), x = read_int();
		switch (opt)
		{
		case 1:
			insert(root, x);
			break;
		case 2:
			remove(root, x);
			break;
		case 3:
			printf("%d\n", Rank(root, x));
			break;
		case 4:
			printf("%d\n", kth(root, x));
			break;
		case 5:
			printf("%d\n", pre(root, x));
			break;
		case 6:
			int tmp=nex(root, x);
			printf("%d\n", tmp);
			break;

		}
	}
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
int read(){
    int q=0,w=1;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}
const int maxn=100;
int n,tot,rt;
int siz[maxn],s[maxn][2],w[maxn],pos[maxn];
void up(int i){siz[i]=siz[s[i][0]]+siz[s[i][1]]+1;}
void spin(int &i,int p){
    int t=s[i][p];
    s[i][p]=s[t][!p],s[t][!p]=i,up(i),up(t),i=t;
}
void ins(int x,int &i){
    if(!i){i=++tot,siz[i]=1,w[i]=x,pos[i]=rand();return;}
    siz[i]++;
    if(x<=w[i]){ins(x,s[i][0]);if(pos[s[i][0]]<pos[i])spin(i,0);}
    else {ins(x,s[i][1]);if(pos[s[i][1]]<pos[i])spin(i,1);}
}
int pre(int x,int i){
    if(!i)return -2000000005;
    if(w[i]<x)return max(w[i],pre(x,s[i][1]));
    else return pre(x,s[i][0]);
}
int nxt(int x,int i){
    if(!i)return 2000000005;
    if(w[i]>x)return min(w[i],nxt(x,s[i][0]));
    else return nxt(x,s[i][1]);
}
int ask(int x,int i){
    if(siz[s[i][0]]==x-1)return w[i];
    if(siz[s[i][0]]>=x)return ask(x,s[i][0]);
    return ask(x-siz[s[i][0]]-1,s[i][1]);
}
int find(int x,int i){
    if(!i)return 1;
    if(w[i]>=x)return find(x,s[i][0]);
    return find(x,s[i][1])+siz[s[i][0]]+1;
}
void del(int x,int &i){
    if(w[i]==x){
        if(s[i][0]*s[i][1]==0){i=s[i][0]+s[i][1];return;}
        if(pos[s[i][0]]>pos[s[i][1]]){spin(i,1);del(x,s[i][0]);}
        else {spin(i,0);del(x,s[i][1]);}
    }
    else if(w[i]>x)del(x,s[i][0]);
    else del(x,s[i][1]);
    up(i);
}
int main()
{
	freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
    int x,y;
    n=read();srand(n);
    while(n--){
        x=read();y=read();
        if(x==1)ins(y,rt);
        else if(x==2)del(y,rt);
        else if(x==3)printf("%d\n",find(y,rt));
        else if(x==4)printf("%d\n",ask(y,rt));
        else if(x==5)printf("%d\n",pre(y,rt));
        else if(x==6)printf("%d\n",nxt(y,rt));
    }
    return 0;
}*/