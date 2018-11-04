//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 10
using namespace std;
int n;
int data[MAXN];
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}

#define INF 1e18

long long divsor[100];
int dcnt=0;
long long dmi=INF;

//输入一个long long 范围内的素数，是素数返回true，否则返回false。定义检测次数TIMES,错误率为(1/4)^TIMES
#define TIMES 10

long long GetRandom(long long n)
{
    //cout<<RAND_MAX<<endl;
    long long num = (((unsigned long long)rand() + 100000007)*rand())%n;
    return num+1;
}

long long Mod_Mul(long long a,long long b,long long mod)
{
    long long msum=0;
    while(b)
    {
        if(b&1) msum = (msum+a)%mod;
        b>>=1;
        a = (a+a)%mod;
    }
    return msum;
}

long long Quk_Mul(long long a,long long b,long long mod)
{
    long long qsum=1;
    while(b)
    {
        if(b&1) qsum=Mod_Mul(qsum,a,mod);
        b>>=1;
        a=Mod_Mul(a,a,mod);
    }
    return qsum;
}

bool Miller_Rabin(long long n)
{
    if(n==2||n==3||n==5||n==7||n==11) return true;
    if(n==1||n%2==0||n%3==0||n%5==0||n%7==0||n%11==0) return false;
    int div2=0;
    long long tn=n-1;
    while( !(tn%2) )
    {
        div2++;
        tn/=2;
    }
    for(int tt=0;tt<TIMES;tt++)
    {
        long long x=GetRandom(n-1); //随机得到[1,n-1]
        if(x==1) continue;
        x=Quk_Mul(x,tn,n);
        long long pre=x;
        for(int j=0;j<div2;j++)
        {
            x = Mod_Mul(x, x, n);
            if(x==1&&pre!=1&&pre!=n-1) return false;
            pre=x;
        }
        if(x!=1) return false;
    }
    return true;
}

long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

long long pollard_rho(long long dn,long long dc)
{
    long long x,y,d,i=1,k=2;
    x = GetRandom(dn-1);
    y = x;
    while(1)
    {
        i++;
        x = (Mod_Mul(x, x, dn) + dc)%dn;
        d = gcd( y-x , dn );
        if(1 < d && d < dn )
            return d;
        if( y==x ) return dn;
        if( i==k )
        {
            y=x;
            k <<= 1;
        }
    }
}


void Divide(long long dn,int dk)
{
    if(dn==1) return ;
    if( Miller_Rabin(dn) == true )
    {
        divsor[dcnt++]=dn;
        dmi = min(dmi,dn);
        return ;
    }
    long long dtmp=dn;
    while(dtmp>=dn) dtmp = pollard_rho(dtmp,dk--);//随机寻找dn的因子，dtmp
    Divide(dtmp, dk);
    Divide(dn/dtmp,dk);
}
int x[MAXN][100];
int cot[MAXN][4000];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
    {
        data[i]=read_int();
        memset(divsor,0,sizeof(divsor));
        Divide(data[i],222);
        int j;
        for(j=0;divsor[j]!=0;j++)
            x[i][j]=divsor[j];
        
    }
    int t=1;
    return 0;
}