
#incldue <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
int s[14],n,sum=0;
int is(int x,int y)
{
    register int i;
    for(i=1;i<=x-1;i++)
        if((abs(x-i)==abs(y-s[i]))||(s[i]==y)) 
            return 0;
    return 1;
}
int search(int x)
{
    register int i,flag=0;
    register int ai,aj;
    if(x==n+1)
    {
        sum++;
        if(sum<=3)    
        {
            for(i=1;i<=n;i++)
                printf("%d ",s[i]);
            printf("\n");
        }
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(is(x,i))
        {
            s[x]=i;
    /*    for(ai=1;ai<=x;ai++)
                printf("%d ",s[ai]);
            printf("\n");
            system("pause");*/
            search(x+1);
        }
    }
    return 0;
}
int main()
{   
    scanf("%d",&n);
    search(1);
    printf("%d\n",sum);
    return 0;
}