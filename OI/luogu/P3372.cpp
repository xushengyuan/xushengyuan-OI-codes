//Date:2017/8/30
//OJ:luogu
//Problem:3373
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 101000
using namespace std;
long long sum[MAXN<<2],add[MAXN<<2];
long long data[MAXN];
long long n,m;
void buildST(long long left,long long right,long long p)
{
    if(left==right)
    {
        sum[p]=data[left];
        return ;
    }
    long long mid=(left+right)/2;
    buildST(left,mid,p*2);
    buildST(mid+1,right,p*2+1);
    sum[p]=sum[p*2]+sum[p*2+1];
}
void  point_change(long long m,long long ad,long long left,long long right,long long p)
{
    if(left==right)
    {
        sum[p]+=ad;
        return ;
    }
    long long mid=(left+right)/2;
    if(m<=mid)
        point_change(m,ad,left,mid,p*2);
    else
        point_change(m,ad,mid+1,right,p*2+1);
    sum[p]=sum[p*2]+sum[p*2+1];
}
void update_down(long long len_l,long long len_r,long long p)
{
    if(add[p]==0) return ;
    add[p*2]+=add[p];
    add[p*2+1]+=add[p];
    sum[p*2]+=add[p]*len_l;
    sum[p*2+1]+=add[p]*len_r;
    add[p]=0;
}
void seg_change(long long m_left,long long m_right,long long ad,long long left,long long right,long long p)
{
    if(m_left <= left && right <= m_right)
    {
        sum[p]+=ad*(right - left + 1);
        add[p]+=ad;
        return;
    }
    long long mid =(left + right)/2;
    update_down(mid-left+1,right-mid,p);
    if(m_left <= mid)
        seg_change(m_left,m_right,ad,left,mid,p*2);
    if(m_right > mid )
        seg_change(m_left,m_right,ad,mid+1,right,p*2+1);
    sum[p]=sum[p*2]+sum[p*2+1];
    return;
}
long long seg_que(long long m_left,long long m_right,long long left,long long right,long long p)
{
    if(m_left <= left && right <= m_right) 
        return sum[p];
    long long mid =(right + left) / 2;
    update_down(mid-left+1,right-mid,p);
    long long result=0;
    if(m_left <= mid)
        result+=seg_que(m_left,m_right,left,mid,p*2);
    if(m_right > mid)
        result+=seg_que(m_left,m_right,mid+1,right,p*2+1);
    return result;
}
long long read_long()
{
    long long result=0;
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
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>m;
    for(long long i=1;i<=n;i++)
        data[i]=read_long();
    buildST(1,n,1);
    long long t,x,y,k;
    for(long long i=1;i<=m;i++)
    {
        //for(long long j=1;j<=n;j++)
        //    cout <<seg_que(j,j,1,n,1)<<' ';
        //cout <<endl;
        t=read_long();
        x=read_long();
        y=read_long();
        if(t==1)
        {
            k=read_long();
            seg_change(x,y,k,1,n,1);
        }
        else if(t==2)
        {
            cout <<seg_que(x,y,1,n,1)<<endl;
        }
    }

    return 0; 
}