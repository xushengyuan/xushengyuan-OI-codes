#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int n,m,s,t;
vector<int> rv_map[MAXN],_map[MAXN];
bool con[MAXN],safe[MAXN];
void pre_bfs(int sou)
{
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(sou);
	vis[sou]=true;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		con[p]=true;
		for(int i=0;i<rv_map[p].size();i++)
			if(!vis[rv_map[p][i]])
			{
				q.push(rv_map[p][i]);
				vis[rv_map[p][i]]=true;
			}
	}
	return ;
}
int bfs()
{
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> >q;
	q.push({s,0});
	vis[s]=true;
	pair<int,int> p=q.front();
	bool flag=false;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p.first==t) 
		{
			flag=true;
			break;
		}
		//cout <<p.first<<'|'<<endl;
		for(int i=0;i<_map[p.first].size();i++)
		{
			if(vis[_map[p.first][i]])	
				continue;
			q.push({_map[p.first][i],p.second+1});
			//cout <<q.front().first<<'^'<<endl;
			vis[_map[p.first][i]]=true;
		}
	}
	if(flag)
		return p.second;
	else	
		return -1;
}
int main()
{
	#ifdef DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
	cin>>n>>m;
	int tx,ty;
	for(int i=0;i<m;i++)
	{
		cin>>tx>>ty;
		tx--,ty--;
		rv_map[ty].push_back(tx);
	}
	cin>>s>>t;
	t--,s--;
	memset(con,0,sizeof(con));
	pre_bfs(t);
	for(int i=0;i<n;i++)
	{
		//cout <<con[i]<<endl;
		safe[i]=con[i];
	}
	for(int i=0;i<n;i++)
	{
		if(!con[i])
			for(int j=0;j<rv_map[i].size();j++)
				safe[rv_map[i][j]]=false;
	}
	/*for(int i=0;i<n;i++)
		//cout <<safe[i]<<endl;*/
	for(int i=0;i<n;i++)
		if(safe[i])
			for(int j=0;j<rv_map[i].size();j++)
				if(safe[rv_map[i][j]])
					_map[rv_map[i][j]].push_back(i);
	/*for(int i=0;i<n;i++)
		for(int j=0;j<_map[i].size();j++)
			cout <<i<<' '<<_map[i][j]<<endl;*/
	cout <<bfs();
}
