//Date:2018/2/4
//OJ:Codeforces
//Problem:EDU 37-A
//Solution: None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int t;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n,k,min_time=-1;
        cin>>n>>k;
        int a,b=0;
        for(int i=0;i<=k;i++)
        {
            a=b;
            if(i<k)
                cin>>b;
            else
                b=n+1;
            int len=b-a-1;
            if(i!=0 && i!= k)
            {
                len/=2;
                if(len%2==1)
                    len++;
            }
            min_time=max(min_time,len+1);
        }
        cout<<min_time<<endl;
    }
    return 0;
}