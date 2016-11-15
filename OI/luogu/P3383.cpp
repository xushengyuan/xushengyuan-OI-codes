#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10000010;  
bool com[MAXN];  
int primes, prime[MAXN/10]; 
void solve(int n)  
{  
    primes = 0;  
    memset(com,false,sizeof(com));  
    com[0] = com[1] = true;  
    for (int i = 2; i <= n; ++i)  
    {  
        if (!com[i])  
        {  
            prime[++primes] = i;  
        }  
        for (int j = 1; j <= primes && i*prime[j] <= n; ++j)  
        {  
            com[i*prime[j]] = true;  
            if (!(i % prime[j]))  
                break;  
        }  
    }  
}  

int main()
{
    int n,i,m,t;
    cin>>n>>m;
    solve(n);
    for(i=0;i<m;i++)
    {
        cin>>t;
        if(!com[t])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}