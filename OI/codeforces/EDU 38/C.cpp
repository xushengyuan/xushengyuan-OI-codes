//Date:2018/2/16
//OJ:Codeforces
//Problem:EDU 38 C
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int t;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>t;
    for(int k=0;k<t;k++)   
    {
        int x;
        bool flag=false;
        cin>>x;
        for(int n=1;n<ceil(sqrt(x))+5;n++)
        {
            for(int m=1;m<=n;m++)
                if(n*n-ceil((double)(n-m+1)/(double)(m))*ceil((double)(n-m+1)/(double)(m))==x)
                {
                    cout<<n<<' '<<m<<endl;
                    flag=true;
                    break;
                }
            if(flag)
                break;
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}