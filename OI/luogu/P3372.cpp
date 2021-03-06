//Date:2017/8/30
//OJ:luogu
//Problem:3373
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000100
#define _DEBUG
using namespace std;
long long Min[MAXN<<2],add[MAXN<<2];
long long data[MAXN];
long long n,m;
void buildST(long long left,long long right,long long p)
{
    if(left==right)
    {
        Min[p]=data[left];
        return ;
    }
    register long long mid=(left+right) >>1;
    buildST(left,mid,(p<<1));
    buildST(mid+1,right,(p<<1)+1);
    Min[p]=min(Min[p<<1],Min[(p<<1)+1]);
}
inline void update_down(long long len_l,long long len_r,long long p)
{
    if(add[p]==0) return ;
    add[p<<1]+=add[p];
    add[(p<<1)+1]+=add[p];
    Min[p<<1]+=add[p];
    Min[(p<<1)+1]+=add[p];
    add[p]=0;
}
void seg_change(long long m_left,long long m_right,long long ad,long long left,long long right,long long p)
{
    if(m_left <= left && right <= m_right)
    {
        Min[p]+=ad;
        add[p]+=ad;
        return;
    }
    register long long mid =(left + right) >>1;
    update_down(mid-left+1,right-mid,p);
    if(m_left <= mid)
        seg_change(m_left,m_right,ad,left,mid,p<<1);
    if(m_right > mid )
        seg_change(m_left,m_right,ad,mid+1,right,(p<<1)+1);
    Min[p]=min(Min[p<<1],Min[(p<<1)+1]);
    return;
}
long long seg_que(long long m_left,long long m_right,long long left,long long right,long long p)
{
    if(m_left <= left && right <= m_right) 
        return Min[p];
    register long long mid =(right + left) >>1;
    update_down(mid-left+1,right-mid,p);
    long long result=0x7ffffffffff;
    if(m_left <= mid)
        result=min(result,seg_que(m_left,m_right,left,mid,p<<1));
    if(m_right > mid)
        result=min(result,seg_que(m_left,m_right,mid+1,right,(p<<1)+1));
    return result;
}
inline long long read_long()
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
    for(register int i=1;i<=n;i++)
        data[i]=read_long();
    buildST(1,n,1);
    register long long t,x,y,k;
    for(register int i=1;i<=m;i++)
    {
        //for(long long j=1;j<=n;j++)
        //    cout <<seg_que(j,j,1,n,1)<<' ';
        //cout <<endl;
        t=-read_long();
        x=read_long();
        y=read_long();
        seg_change(x,y,t,1,n,1);
        // for(int j=1;j<=n;j++)
        //     cout<<seg_que(j,j,1,n,1)<<' ';
        // cout<<endl;
        int result=seg_que(x,y,1,n,1);
        // cout<<result<<endl;
        if(result<0)
        {
            cout<<-1<<endl;
            cout<<i<<endl;
            exit(0);
        }
    }
    cout<<0<<endl;
    return 0; 
}