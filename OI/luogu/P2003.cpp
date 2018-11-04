//Date:2018/10/5
//OJ:luogu
//Problem:2003
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 110
#define INF 0x3fffffff
using namespace std;
struct plate{
    int l,r,h;
}data[MAXN];
int ans=0,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++) 
        cin>>data[i].h>>data[i].l>>data[i].r;
    for(int i=0;i<n;i++)
    {
        int pl=data[i].l,pr=data[i].r,ph=data[i].h;
        int hl=INF,hr=INF;
        for(int j=0;j<n;j++)
            if(i!=j)
            {
                int ql=data[j].l,qr=data[j].r,qh=data[j].h;
                if(ph>qh&&pl+0.5>ql&&pl+0.5<qr)
                    hl=min(hl,ph-qh);
                if(ph>qh&&pr-0.5<qr&&pr-0.5>ql)
                    hr=min(hr,ph-qh);
            }
        hl=min(hl,ph);
        hr=min(hr,ph);
        ans+=(hl+hr);
    }
    cout<<ans;
    return 0;
}