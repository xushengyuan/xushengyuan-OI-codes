#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int l,n,m;
int data[50010];
bool ch(int x)
{
    int i,ans=0,t=0;
    for(i=1;i<n;i++)
    {
        if(data[i]-t<x)
        {
            ans++;
            continue;
        }
        if(ans>m)
            return false;
        else
            return true;
    }
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,mi=2147483647;
    cin>>l>>n>>m;
    for(i=1;i<=n-1;i++)
    {
        cin>>data[i];
        mi=min(mi,data[i]-data[i-1]);
    }
    int mid,right,left;
    data[n]=l;
    right=l;
    left=mi;
    while(left+1<right)
    {
        mid=(left+right)/2;
        if(ch(mid))
            left=mid;
        else
            right=mid;        
    }
    cout<<ch(right)?right:left;
    return 0;
} 
