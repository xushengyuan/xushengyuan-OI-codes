#include <bits/stdc++.h>
#define MAXN 100000
#define MAXNN 100000
using namespace std;
int a,b,p;
int prime[MAXNN+100],prime_count=0;
bool not_prime[MAXNN+100];
void pre_prime()
{
    memset(not_prime,0,sizeof(not_prime));
    not_prime[1]=true;
    for(int i=2;i<=MAXNN;i++)
    {
        if(!not_prime[i])
            prime[++prime_count]=i;
        for(int j=1;j<=prime_count;j++)
        {
            if(prime[j]*i>MAXNN)
                break;
            not_prime[prime[j]*i]=true;
            if(i%prime[j]*i==0)
                break;
        }
    }
    return;
}
int dad[MAXN];
int find(int x)
{
    return dad[x]==x?x:dad[x]=find(dad[x]);
}
int main()
{
    cin >>a>>b>>p;
    int t;
    pre_prime();
    for(int i=a;i<=b;i++)
        dad[i]=i;
    for(int i=p;i<=b/2;i++)
        if(!not_prime[i])
            for(int j=i,t=0;j<=b;j+=i)
                if(j>=a)
                    if(t==0)
                        t=find(j);
                    else
                        dad[find(j)]=t;
    int result=0;
    for(int i=a;i<=b;i++)
        if(find(i)==i)
            result++;
    cout<<result;
    //system("pause");
}