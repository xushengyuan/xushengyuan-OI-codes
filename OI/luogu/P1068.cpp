#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int nozomi,maki,umi[5000],honoko[5000];
void swap(int a,int b)
{
    int t1,t2;
    t1=umi[a];
    t2=honoko[a];
    umi[a]=umi[b];
    honoko[a]=honoko[b];
    umi[b]=t1;
    honoko[b]=t2;
    return ;
}
void qsort(int left,int right)
{
    int f;
    int rtemp,ltemp;
    ltemp=left;
    rtemp=right;
    f=umi[(left+right)/2];
    while(ltemp<rtemp)
    {
        while(umi[ltemp]<f)
            ++ltemp;
        while(umi[rtemp]>f)
            --rtemp;
        if(ltemp<=rtemp)
        {
            swap(ltemp,rtemp);
            --rtemp;
            ++ltemp;
        }
    }
    if(ltemp==rtemp)
        ltemp++;
    if(left<rtemp)
        qsort(left,ltemp-1);
    if(ltemp<right)
        qsort(rtemp+1,right);
    return ;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>nozomi>>maki;
    int rin,hanayo;
    for(rin=0;rin<nozomi;rin++)
        cin<<umi[rin]<<nozomi[rin];
    qsort(0,nozomi)
    for(rin=0;rin<nozomi;rin++)
        cout<<umi[rin]<<' '<<honoko[rin]<<endl;
    return 0;
}