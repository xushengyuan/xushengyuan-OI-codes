#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX_N 100
using namespace std;
struct people{
    string name;
    int mark,point ;
    bool is_gb,is_xb;
    int artnum;
    int money;
}data[MAX_N];
int n,sum=0,mx=0;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    char temp1,temp2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data[i].name>>data[i].mark>>data[i].point;
        cin>>temp1>>temp2>>data[i].artnum;
        if(temp1=='Y')
            data[i].is_gb=true;
        else
            data[i].is_gb=false;
        if(temp2=='Y')
            data[i].is_xb=true;
        else
            data[i].is_xb=false;
        data[i].money=0;
        if(data[i].mark>80 && data[i].artnum>=1)   
            data[i].money+=8000;
        if(data[i].mark>85 && data[i].point>80)
            data[i].money+=4000;
        if(data[i].mark>90)
            data[i].money+=2000;
        if(data[i].is_xb && data[i].mark>85)
            data[i].money+=1000;
        if(data[i].is_gb && data[i].point>80)
            data[i].money+=850;
        sum+=data[i].money;
        if(data[i].money>data[mx].money)
            mx=i;
    }
    /*for(i=0;i<n;i++)
        cout<<data[i].is_gb<<data[i].is_xb<<endl;*/
    cout<<data[mx].name<<endl;
    cout<<data[mx].money<<endl;
    cout<<sum<<endl;
    return 0;
}
