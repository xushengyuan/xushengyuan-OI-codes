//Date:2017/9/15
//OJ:luogu
//Problem:2827
//Solution: queue
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int n,m,q,u,v,t;
double p;
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit())
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
void find_max(int time)
{
    int mx=-0x7fffffff,mxn,len;
    for(int i=0;i<3;i++)
    {
        len=que[i][front[i]].first+(time-que[i][front[i]].second)*q;
        if(len>mx)
        {
            mx=len;
            mxn=i;
        }
    }
    front[mxn]++;
    cut(mx);    
    return ;
}
void cut(int len)
{
    int left=p*len;
    int right=len-left;
    cout <<len<<' ';
    que[1][tail[1]++]=left;
    que[2][tail[2]++]=right;
}
pair<int,int> que[3][MAXN*100],front[3]={0},tail[3]={0};
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}