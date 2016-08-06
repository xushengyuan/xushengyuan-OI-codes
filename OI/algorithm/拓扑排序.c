#include<stdio.h>
#include<string.h>
#define clr(x)memset(x,0,sizeof(x))
int g[102][102];
int indegree[102];
int res[102];
int main()
{
	int p,i,j,k,n,top;
	while(scanf("%d",&n)!=EOF)
	{
		clr(g);
		clr(indegree);
		for(i=1; i<=n; i++)
			while(scanf("%d",&p),p)
			{
				g[i][p]=1;
				indegree[p]++;
			}
		top=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				if(indegree[j]==0)
				{
					res[top++]=j;
					indegree[j]=-1;
					for(k=1; k<=n; k++)
						if(g[j][k]==1)
							indegree[k]--;
					break;
				}
		}
		for(i=0; i<top; i++)
			printf("%d%c",res[i],i==top-1?'\n':' ');
	}
	return 0;
}
