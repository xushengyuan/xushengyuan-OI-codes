//Date:2017/9/20
//OJ:luogu
//Problem:1514
//Solution: DP+BFS
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 510
using namespace std;
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

int n,m;
int data[MAXN][MAXN],f[MAXN];
bool vis[MAXN][MAXN];
pair<int,int> segs[MAXN];
queue<pair<int,int> > q;
inline void BFS()
{
    int px,py;
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        vis[p.first][p.second]=true;
        //cout <<p.first<<' '<<p.second<<endl;
        px=p.first-1,py=p.second;
        if(px>=0 && !vis[px][py] && data[px][py]<data[p.first][p.second])
        {
            q.push({px,py});
            vis[px][py]=true;
    	}
        px=p.first+1,py=p.second;
        if(px<n && !vis[px][py] && data[px][py]<data[p.first][p.second])
        {
            q.push({px,py});
            vis[px][py]=true;
    	}
        px=p.first,py=p.second+1;
        if(py<m && py>=0&& !vis[px][py] && data[px][py]<data[p.first][p.second])
        {
            q.push({px,py});
            vis[px][py]=true;
    	}
        px=p.first,py=p.second-1;
        if(py<m && py>=0&& !vis[px][py] && data[px][py]<data[p.first][p.second])
        {
            q.push({px,py});
            vis[px][py]=true;
    	}
    }
    return ;
}
inline void vis_out()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout <<vis[i][j]<<' ';
        cout <<endl;
    }
}
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    //#endif
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            data[i][j]=read_int();
    for(int i=0;i<m;i++)
        q.push({0,i});
    //q.push({0,5});
    BFS();
    int tot=0;
    for(int i=0;i<m;i++)
        if(!vis[n-1][i])
            tot++;
    if(tot!=0)
    {
        cout <<0<<endl<<tot;
        exit(0);
    }
    else
    {
    	int segsum=1;
		for(int i=0;i<m;i++)
		{
			if(data[0][i-1]<=data[0][i]&&data[0][i+1]<=data[0][i])
			{
			q.push({0,i});
			BFS();
			for(int a=0;a<n;a++)
			{
				for(int b=0;b<m;b++)
					cout<<vis[a][b]<<' ';
				cout <<endl;
			}
			for(int j=0;j<m;j++)
				if(vis[n-1][j])
				{
					segs[segsum].first=j;
					break;
				}
				segs[segsum].second=-1;
			for(int j=segs[segsum].first;j<m;j++)
				if(!vis[n-1][j])
				{
					segs[segsum].second=j-1;
					break;
				}
			if(segs[segsum].second==-1)
				segs[segsum].second=m-1;
			cout<<segs[segsum].first<<'-'<<segs[segsum].second<<endl;
			segs[segsum].first++,segs[segsum].second++;
			segsum++;
			}
		}
		sort(segs,segs+segsum);
		//for (int i=1;i<segsum;i++)
		//	cout<<segs[i].first<<'-'<<segs[i].second<<endl;
		int f[MAXN];
		memset(f,0x3f,sizeof(f));
		f[0]=0;
		for (int i=0;i<segsum;i++)
            for (int j=segs[i].first;j<=segs[i].second;j++)
                f[j]=min(f[j],f[segs[i].first-1]+1);
        cout<<1<<endl<<f[m];
        /*int p1=1,p2=0,sum=0;
        segs[segsum]={1111111111,111111111};
    	while(p2<segsum)
    	{
    	    while (segs[p1+1].first<=p2+1) p1++;
    	    p2=segs[p1].second;
   		    p1++;
  	        sum++;
    	}
        cout<<1<<endl<<sum;*/
    }
    return 0;
}
