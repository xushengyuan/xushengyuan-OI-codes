#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int sum=2147483647,maki[200010],kke[200010],s[200010];
int tmp;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(kke,0,sizeof(int));
    int i,j,t,flag,t2;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>maki[i];
    for(i=1;i<=n;i++)
    {
        if(kke[i]!=0)
            continue;
        t=i;
        tmp=0;
        flag=0;
        while(!s[t])
        {
            kke[t]=tmp;
            s[t]=i;
            t=maki[t];
            tmp++;
            if(tmp>sum)
            {
                flag=1;
                break;
            }
        }
        if(s[t]!=i || flag)
            continue;
        t2=tmp-kke[t];
        sum=min(sum,t2);
    }
    cout<<sum;
    getchar();
    return 0;
}
