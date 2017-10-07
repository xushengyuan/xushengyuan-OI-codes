//Date:2017/10/7
//OJ:luogu
//Problem:2393
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    long double sum=0,a;
    while(scanf("%Lf",&a)!=EOF)
    {
        sum=sum+a*1000000;
    }
    printf("%.5Lf",sum/1000000);
    return 0;
}