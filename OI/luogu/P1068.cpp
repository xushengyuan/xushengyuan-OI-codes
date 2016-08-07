#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int nozomi,maki;
struct n
{
    int umi;
    int honoko;
}nico[5000];
bool cp(n a,n b)
{
    if(a.honoko==b.honoko)
        return a.honoko>b.honoko;
    return a.honoko>b.honoko;
}
/*void swap(int a,int b)
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
    int f,f_num;
    int rtemp,ltemp;
    ltemp=left;
    rtemp=right;
    f=honoko[(left+right)/2];
    f_num=(left+right)/2;
    while(ltemp<rtemp)
    {
        while(cp(ltemp,f_num))
            ++ltemp;
        while(!cp(rtemp,f_num))
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
}*/
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>nozomi>>maki;
    //cout<<nozomi<<maki;
    int rin,hanayo;
    for(rin=0;rin<nozomi;rin++)
        cin>>nico[rin].umi>>nico[rin].honoko;
    sort(nico,nico+nozomi,cp);
    //cout<<nozomi<<maki;
    /*for(rin=0;rin<nozomi;rin++)
        cout<<umi[rin]<<' '<<honoko[rin]<<endl;*/
    int kotori=(int)(1.5*maki);
    for(int rin=kotori;rin<nozomi;rin++)
        if(nico[rin].honoko==nico[kotori-1].honoko)
            kotori++;
    cout<<nico[kotori-1].honoko<<' '<<kotori<<endl;
    for(rin=0;rin<kotori;rin++)
        cout<<nico[rin].umi<<' '<<nico[rin].honoko<<endl;
    return 0;
}
