#include<iostream>
 using namespace std;
 int main()
 {
    int a,b,i=1,n;
    cin>>n;
    while(n) 
        for(a=i++,b=1;--n&&b<i-1;a--,b++);            
    cout<<a<<'/'<<b;
    return 0;
 }