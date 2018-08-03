//Date:2018/7/9
//OJ:luogu
//Problem:1315
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 20
#define MAXM 110
using namespace std;
int n,m,k;
int d[MAXN],a[MAXM],b[MAXM],t[MAXM],begintn[MAXM],endtn[MAXN];
int tts[(MAXN+MAXM)*10],ts[MAXN+MAXM],tsd[MAXN+MAXM],tsdw[MAXN+MAXM],tsdws[MAXN+MAXM],nt=0,p=0;
pair<int,int> fin[MAXN+MAXM];
int finp=0;
bool cmp(pair<int,int> a,pair<int,int>b)
{
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first>b.first;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m>>k;
    for(int i=0;i<n-1;i++)
        cin>>d[i];
    memset(begintn,0,sizeof(begintn));
    for(int i=0;i<m;i++)
    {
        cin>>t[i]>>a[i]>>b[i];
        begintn[a[i]]=max(begintn[a[i]],t[i]);
    }
    begintn[0]=-0x7fffffff;
    for(int i=1;i<=n;i++)  
    {
        begintn[i]=max(begintn[i],begintn[i-1]+d[i-2]);
        tts[nt]=begintn[i];
        nt++;
        endtn[i]=begintn[i]+d[i-1];
    }
    memset(tsd,0,sizeof(tsd));
    for(int i=0;i<m;i++)
    {
        tts[nt]=t[i];
        nt++;
        tts[nt]=endtn[b[i]-1];
        nt++;
    }
    sort(tts,tts+nt);
    ts[0]=tts[0];p=1;
    for(int i=1;i<nt;i++)
    {
        if(tts[i]!=ts[p-1])
        {
            ts[p]=tts[i];
            p++;
        }
    }
    int pos;
    for(int i=0;i<m;i++)
    {
        pos=lower_bound(ts,ts+p,t[i])-ts;
        tsd[pos]++;
        pos=lower_bound(ts,ts+p,endtn[b[i]-1])-ts;
        tsd[pos]--;
    }
    int tmp=0,tot=0;
    for(int i=0;i<p;i++)
    {
        tmp+=tsd[i];
        tsdw[i]=tmp;
        tot+=tsdw[i]*(ts[i+1]-ts[i]);
    }
    int pn=1;
    for(int i=0;i<p-1;i++)
    {
        if(ts[i]>=begintn[pn] && ts[i+1]<=endtn[pn])
        {
            fin[finp++]=make_pair(tsdw[i],ts[i+1]-ts[i]);
            if(ts[i+1]==endtn[pn])
                pn++;
        }
    }
    sort(fin,fin+finp,cmp);
    int tt=k,cot=0;
    for(int i=0;i<finp;i++)
    {
        if(tt>fin[i].second)
        {
            cot+=fin[i].first*fin[i].second;
            tt-=fin[i].second;
        }
        else if(tt<=fin[i].second)
        {
            cot+=fin[i].first*tt;
            break;
        }
    }
    #ifdef _DEBUG
        cout<<cot<<endl<<tot<<endl;
    #endif
    cout<<tot-cot;
    return 0;
}