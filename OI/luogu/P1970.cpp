#include <bits/stdc++.h>
using namespace std;
int n,t,p,flag=0,result;
int main()
{
	//freopen("in.txt","r",stdin);
    cin>>n>>p;
    for (int i=2;i<=n;i++)
    {
        cin>>t;
        if (t-p!=0)
            if (flag==0 || (flag==1&&t<p) || (flag==-1&&t>p))
            {
                result++;
                flag=t-p>0?1:-1;
            }
        p=t;
    }
    cout <<result+1;
    return 0;
}
