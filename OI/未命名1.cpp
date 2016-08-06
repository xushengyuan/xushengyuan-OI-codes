#include<iostream>

using namespace std;
int high[10];
int main()
{
    int n,a=0,i;
    for(i=0;i<10;i++)
        cin >>high[i];
    cin>>n;
    for(i=0;i<10;i++)
        if(high[i]<=30+n)
            a++;
    cout <<a;
    return 0;
}
