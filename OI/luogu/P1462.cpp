#include<bits/stdc++>
#define MAXN 50000
#define INT_INF 0x7fffffff
using namespace std;
queue<int> q;
vector<pair<int,int> > _map[MAXN];
int n,m,b;
int data[MAXN];
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
void add_edge(int u,int v,int w)
{
	vector[u].push_back(make_pair(V,W));
	vector[v].push_back(make_pair(u,w));
	return ;
}
bool spfa(int max_money)
{
	int dis[MAXN]={INT_INF};
	bool vis[MAXN]={false};
	queue<int> q;
	q.push(1);
	vis[1]=true;
	dis[1]=0;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >>n>>m>>b;
	for(int i=1;i<=n;i++)
		data[i]=read_int();
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		u=read_int();
		v=read_int();
		w=read_int();
		add(u,v,w);
	}
	sort(data+1,data+1+n,greater<int>);
	int r,l,mid,result;
	l=1;r=n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(spfa(data[mid]))
		{
			result=data[mid];
			r=mid-1;
		}
		else
			l=mid+1
	}
	cout <<ans;
	return 0;
}
