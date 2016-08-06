vector<int> adj[N];
int low[N],dfn[N],id[N],sta[N],idx,top,scnt;//scnt��1��ʼ
bool insta[N];
void tarjan(int u)
{
	insta[u]=1;
	sta[top++]=u;
	low[u]=dfn[u]=++idx;
	for(int i=0; i<(int)adj[u].size(); i++)
	{
		int v=adj[u][i];//��vector��ĵ�
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
			//vis[tmp]=0;����д���ˡ�
			insta[tmp]=0;//Ӧ���ǰ���ջ�еı��ȡ����
			id[tmp]=scnt;
		}
		while(tmp!=u);
	}
}
