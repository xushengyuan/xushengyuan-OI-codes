#include <bits/stdc++.h>
#define MAXN 30
using namespace std;
char sa[MAXN],sb[MAXN],sc[MAXN];
int tmp[MAXN];
bool visit[MAXN];
int n;
void dfs(int x,int y,int add)
{
    for(int i=0;i<x;i++)
    {
        int a=tmp[sa[i]],b=tmp[sb[i]],c=tmp[sc[i]];
        if((a!=-1 && b!=-1 && c!=-1)&&(a+b)%n!=c && (a+b+1)%n!=c)
            return ;
    }//出口一：判断已经确定三个数字的是否满足，如果存在不满足的情况就退出。
    if(x==0 && add==0)
    {
        for(int i=0;i<n;i++)
            cout<<tmp[i]<<' ';
        exit(0);
    }//出口二：搜索完毕，退出。
    int a=tmp[sa[x]],b=tmp[sb[x]],c=tmp[sc[x]];
    if(y==1 && a!=-1)
    {
        dfs(x,2,add);
        return ;
    }//情况一：要搜的第一行已经被填充了，开始填充该列的第二行。
    else if(y==1 && a==-1)
    {
        for(int i=n-1;i>=0;i--)
        {
            tmp[sa[x]]=i;
            visit[i]=true;
            dfs(x,2,add);
            visit[i]=false;
            tmp[sa[x]]=-1;
        }
        return ;
    }//情况二：要搜的第一行还没有被填充，搜该列第一行。
    else if(b!=-1)
    {
        int t=a+b+add;
        if(t%n==c)
            dfs(x-1,1,t/n);//该列条件满足，开始填充下一列
        else if(c==-1)
        {
            tmp[sc[x]]=t%n;
            visit[t%n]=true;
            dfs(x-1,1,t/n);
            visit[t%n]=0;
            tmp[sc[x]]=-1;
        }//该列第三行可被推出，搜索该填充尝试
        return ;
    }//情况三：要搜的是第二行，但已被填充，推出第三行，并且继续填充该行和判断。
    else 
    {
        for(int i=n-1;i>=0;i++)
        {
            int t=a+i+add;
            if((visit[i])||
               (t%n!=c && c!=-1)||
               (visit[t%n]&&c==-1))
                continue;
            if(c==-1)
            {
                visit[t%n]=true;
                tmp[sc[x]]=t%n;
            }
            tmp[sb[x]]=i;
            visit[i]=false;
        }
    }//情况四：要搜的第二行还没有被填充，搜第二行
}
int main()
{
    freopen("in.txt","r",stdin);
    cin>>n;
    cin>>sa>>sb>sc;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++)
        tmp[i]=-1;
    dfs(n,1,0);
    return 0;
}
