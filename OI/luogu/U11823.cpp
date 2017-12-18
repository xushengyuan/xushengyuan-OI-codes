//Date:2017/10/8	
//OJ:luogu
//Problem:U11823
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int m;
    cin>>m;
    for(int zzz=0;zzz<m;zzz++)
    {
    	int n,_min=0x7fffffff;
    	cin>>n;
    	for(int a=0;a*150<=n;a++)
    	{
    		for(int b=0;b*200+a*150<=n;b++)
    		{
    			for(int c=0;c*300+b*200+a*150<=n;c++)
    				if(c*300+b*200+a*150<=n)
    					_min=min(_min,n-(c*300+b*200+a*150));
			}
		}
		cout<<_min<<endl;
	}
    return 0;
}
