#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll i,p=0,n,sum=0;
    double t,r;
    srand(time(0));
    cin >>n>>r;
    for(i=0;i<n;i++)
    {
        t=(double)rand()/(double)RAND_MAX;
        if(t>=r)
            p++;
        else
            p--;
        //cout<<p<<endl;
        if(p==-1)
            sum++;
    }
    printf("%lf",(double)sum/(double)n);
    system("pause");
    return 0;
}