#include<cstdio>
using namespace std;
int l,n,m,d[50009],lef=233333333,rig,mid,sum,last;
int check(int s)
{
    sum=0,last=0;
    for(int i=1;i<n;i++)//计算要去掉多少个石子
    {
        if(d[i]-last<s){sum++;continue;}
        last=d[i];
    }
    if(sum>m){return 0;}
    else{return 1;}
}
int main()
{
    scanf("%d%d%d",&l,&n,&m);
    n++;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&d[i]);
        if(d[i]-d[i-1]<lef){lef=d[i]-d[i-1];}//左区间为最短长度
    }
    d[n]=l,rig=l;//右区间为最长长度l，并且把l加入石子
    while(lef+1<rig)//二分
    {
        mid=(lef+rig)/2;
        if(check(mid)){lef=mid;}
        else{rig=mid;}
    }
    if(check(rig)){printf("%d",rig);return 0;}额外判断一下
    printf("%d",lef);
    return 0;
}