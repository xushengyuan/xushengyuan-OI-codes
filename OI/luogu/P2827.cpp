//Date:2017/9/15
//OJ:luogu
//Problem:2827
//Solution: queue
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
pair<int,int> que[3][MAXN*100];
int front[3]={0},tail[3]={0};
int n,m,q,u,v,t;
double p;
int read_int()
{
    int result=0;
    char tt;
    tt=getchar();
    while(!isdigit(tt))
        t=getchar();
    while(isdigit(tt))
    {
        result=result*10+tt-'0';
        tt=getchar();
    }
    return result;
}
void cut(int len,int time)
{
    int left=p*len;
    int right=len-left;

    //cout <<len<<':'<<left<<' '<<right<<endl;
    que[1][tail[1]++]={left,time};
    que[2][tail[2]++]={right,time};
    /*for(int i=0;i<3;i++)
    {
    	for(int j=front[i];j<tail[i];j++)
    	{
    		int len=que[i][j].first+(time-que[i][j].second)*q;
    		cout <<len<<' ';
    	}
    	cout <<endl;
	}*/
	
}
int find_max(int time)
{
    int mx=-0x7fffffff,mxn,len;
    for(int i=0;i<3;i++)
    {
    	if(front[i]==tail[i])
    		continue;
        len=que[i][front[i]].first+(time-que[i][front[i]].second)*q;
        if(len>mx)
        {
            mx=len;
            mxn=i;
        }
    }
    front[mxn]++;
    cut(mx,time+1);    
    return mx;
}
bool cmp(int a,int b)
{
	return a>b;
}
bool cmp_p(pair<int,int> a,pair<int,int> b)
{
	return a.first>b.first;
}
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    //#endif
    cin>>n>>m>>q>>u>>v>>t;
    
    p=(double)u/(double)v;
    for(int i=0;i<n;i++)
    {
    	int tt;
    	cin>>tt;
    	que[0][tail[0]++]={tt,0};
	}
	sort(&que[0][0],&que[0][tail[0]-1],cmp_p);
    for(int i=0;i<m;i++)
    	if((i+1)%t==0)
    		cout<<find_max(i)<<' ';
    	else
    		find_max(i);
    cout <<endl;
    vector<int> arr;
    for(int i=0;i<3;i++)
    {
    	if(front[i]==tail[i])
    		continue;
    	for(int j=front[i];j<tail[i];j++)
    	{
    		int len=que[i][j].first+(m-que[i][j].second)*q;
    		arr.push_back(len);
    		//cout <<len<<' ';
    	}
    	//cout <<endl;
	}
    sort(arr.begin(),arr.end(),cmp);
    for(int i=t;i<=arr.size();i+=t)
    	cout <<arr[i-1]<<' ';
    return 0;
}
