#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=200000;
int n,a[maxn],q[maxn],d[maxn],c[maxn],p[maxn],s,t,L,C,l;
long long ans;
int cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	 scanf("%d%d%d",&C,&L,&n);
	 for (int i=1;i<=n;i++)
	 {
	   scanf("%d%d",&a[i],&c[i]);
	   d[i]=i;
	}
	n=n+1;
	c[n]=0; a[n]=L; d[n]=n;
	c[0]=0; p[0]=C; a[0]=0;
	sort(d+1,d+1+n,cmp);
	s=t=1; q[1]=0; ans=0; l=C;
	for (int ii=1;ii<=n;ii++)
	{
		int i=d[ii];
		int tmp=a[i]-a[d[ii-1]];
		l-=tmp;
		for (;t>=s;s++) 
            if (p[q[s]]>tmp) 
            {
                ans+=((long long)tmp)*c[q[s]];
                p[q[s]]-=tmp; 
                tmp=0; 
                break;
            }
		    else 
            {
                ans+=((long long)p[q[s]])*c[q[s]]; 
                tmp-=p[q[s]];
                p[q[s]]=0;
            }
		if (tmp>0) 
        {
            ans=-1; 
            break;
        }
		for (;t>=s;t--) 
            if (c[q[t]]<c[i]) 
                break; 
            else 
                l-=p[q[t]];
		t++; 
        q[t]=i;
		p[i]=C-l; 
        l=C;
	}
	cout<<ans<<endl;
	 
}
