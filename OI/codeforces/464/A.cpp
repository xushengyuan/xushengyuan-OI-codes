#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;
int n;
int data[MAXN],data2[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>data[i];
        data2[data[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(data[data[i]]==data2[i])
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}