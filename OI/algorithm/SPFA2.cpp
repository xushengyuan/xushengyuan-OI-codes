const int N;
const M;
int point[M],to[M],next[M],cc;
int dis[N];
int que[N],top,tail;
bool in[N];
int n,m;

void AddRdge(int x,int y,int z)
{

}

int main()
{
    int i,j;
    scanf("%d%d%d",&a,&b,&c);
    for(i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d%d",&a,&b,&c);
        addEdge(a,b,c);
        addEdge(b,a,c);
    }
    memset(dis,0x3f,sizeod(dis));
    top=0,tail=1,que[1]=1,in[i]=1;
    while(top!=tail)
    {
        top++;
        top%=N;
        int now=que[top];
        int ed=point[now];
        while(ed)
        {
            int tox=to[ed];
            if(dis[tox]>dis[now]+len[ed])
            {
                dis[tox]=dis[now]+len[ed];
                if(!in[tox])
                {
                    tail++;
                    tail%=N;
                    que[tail]=tox;
                    in[tox]=1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
	    printf("%d\n", dis[i]);
}