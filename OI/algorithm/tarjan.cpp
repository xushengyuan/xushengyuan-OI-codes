vector<int> adj[N];
int low[N],dfn[N],id[N],sta[N],idx,top,scnt;//scnt从1开始
bool insta[N];
void tarjan(int u)
{
	insta[u]=1;
	sta[top++]=u;
	low[u]=dfn[u]=++idx;
	for(int i=0; i<(int)adj[u].size(); i++)
	{
		int v=adj[u][i];//用vector存的点
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(insta[v]&&dfn[v]<low[u]) low[u]=dfn[v];
	}
	if(low[u]==dfn[u])
	{
		int tmp;
		++scnt;
		do
		{
			tmp=sta[--top];
			//vis[tmp]=0;这里写错了。
			insta[tmp]=0;//应该是把在栈中的标记取消。
			id[tmp]=scnt;
		}
		while(tmp!=u);
	}
}
