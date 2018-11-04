//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n,m,d;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>d>>m;
    int ld=n-d;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        int lx=n-x,ly=n-y;
        if(x+y<d)
            cout<<"NO"<<endl;
        else if(lx+ly<d)
            cout<<"NO"<<endl;
        else if(lx+y<ld)
            cout<<"NO"<<endl;
        else if(x+ly<ld)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}