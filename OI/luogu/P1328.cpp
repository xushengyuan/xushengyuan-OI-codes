
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,na,nb;
int d[5][5]={{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int a[210],b[210],suma=0,sumb=0;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k,i,j;
    cin>>n>>na>>nb;
    for(i=0;i<na;i++)
        cin>>a[i];
    for(i=0;i<nb;i++)
        cin>>b[i];
    int pa=0,pb=0;
    for(i=0;i<n;i++)
    {
        if(pa==na)
            pa=0;
        if(pb==nb)
            pb=0;
        if(d[a[pa]][b[pb]]==1)
            suma++;
        else if(d[a[pa]][b[pb]]==-1)
            sumb++;
        pa++;
        pb++;
    }
    cout<<suma<<' '<<sumb;
    return 0;
}
