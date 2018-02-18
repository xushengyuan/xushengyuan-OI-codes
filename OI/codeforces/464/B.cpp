#include <bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long result,_max=-1,tmp;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        long long a;
        cin>>a;
        long long t=n-n%a;
        if(t>_max)
        {
            _max=t;
            result=i;
            tmp=(n-n%a)/a;
        }
    }
    cout<<result<<' '<<tmp;
    return 0;
}