#include <bits/stdc++.h>
#define MAXX 130
#define SIZE 128
#define MAXN 25
using namespace std;
int _map[MAXX][MAXX],d,n;
int main()
{
	cin >>d>>n;
	int tx,ty;
	for(int i=0;i<n;i++)
	{
		cin >>tx>>ty;
		cin>>_map[tx][ty];
	}
	int mx=-0x7fffffff,mxx,mxy,sum,mxn=0;
	for(int i=0;i<=SIZE;i++)
		for(int j=0;j<=SIZE;j++)
		{
			sum=0;
			for(int pi=max(0,i-d);pi<=min(SIZE,i+d);pi++)
				for(int pj=max(0,j-d);pj<=min(SIZE,j+d);pj++)
					sum+=_map[pi][pj];
			if(sum>mx)
				mx=sum,mxx=i,mxy=j,mxn=1;
			else if(sum==mx)
				mxn++;
			
		}
	cout <<mxn<<' '<<mx<<endl;
	return 0;
}
