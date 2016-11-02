#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct student
{
    int num,chn,mat,eng,sum;
}data[2000];
bool operator < (const student& A,const student& B)
{
    if(A.sum>B.sum)
        return true;
    else if(A.sum<B.sum)
        return false;
    else if(A.chn>B.chn)
        return true;
    else if(A.chn<B.chn)
        return false;
    else if(A.num<B.num)
        return true;
    else 
        return false;
}
void in(int i)
{
    data[i].num=i;
    cin>>data[i].chn>>data[i].mat>>data[i].eng;
    data[i].sum=data[i].chn+data[i].mat+data[i].eng;
    return ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,n;
    cin>>n;
    for(i=1;i<=n;i++)
        in(i);
    sort(&data[1],&data[n+1]);
    for(i=1;i<6;i++)
        cout<<data[i].num<<' '<<data[i].sum<<endl;
    return 0;
}