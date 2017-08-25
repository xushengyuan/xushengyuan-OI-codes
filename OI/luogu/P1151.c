//Date:2017/8/12
//OJ:luogu
//Problem:1151
//Solution:Simulation
//By:xushengyuan
#include <stdio.h>
int main()
{
    int n;
    bool s=false;
    scanf("%d",&n);
    for(int i=10000 ; i< 30001;i++)
    {
        if(
        (i/10%1000)%n==0&&
        (i/100)%n==0&&
        (i%1000)%n==0)
        {
            printf("%d\n",i);
            s=true;
        }
    }
    if(s==false)
        printf("No");
    return 0;
}