#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX_N 1000
using namespace std;
int n;
double sum=0.0;
struct people
{
    int num,water;
}data[MAX_N];
bool cmp(people a,people b)
{
    return a.water<b.water;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,pre=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data[i].water;
        data[i].num=i+1;
    }   
    sort(&data[0],&data[n],cmp);
    for(i=0;i<n;i++)
    {
        cout<<data[i].num<<' ';
        sum+=pre;
        pre+=data[i].water;
    }
    cout<<endl;
    double x;
    x=sum/n;
    printf("%.2f",sum/n);
    return 0;
}