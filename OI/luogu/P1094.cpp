#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int data[30005];
int n,w,sum=0;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i;
    cin>>w>>n;
    for(i=0;i<n;i++)
        cin>>data[i];
    sort(&data[0],&data[n]);
    int pl,pm;
    pl=0,pm=n-1;
    while(pl<=pm)
    {
        if(data[pl]+data[pm]>w || pl==pm)
        {
            sum++;
            pm--;
        }
        else 
        {
            sum++;
            pl++;
            pm--;
        }
    }
    cout<<sum;
    return 0;
}
