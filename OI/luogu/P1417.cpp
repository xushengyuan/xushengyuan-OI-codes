//Date:2017/8/10
//OJ:luogu
//Problem:1417
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 55
#define LL long long
#define fo(a,b) for(int i=a;i<=b;i++)
using namespace std;
LL n,T;
struct food
{
    int a,b,c;
}foods[MAXN];
LL f[100010]={0}; 
bool cmp(food a,food b)
{
    return a.c*b.b<b.c*a.b;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >> T>>n;
    fo(1,n)
        cin >> foods[i].a;
    fo(1,n)
        cin >> foods[i].b;
    fo(1,n)
        cin >> foods[i].c;
    sort(foods+1,foods+n+1,cmp);

    /*for(int i=1;i<=n;i++)
        for(int j=T;j>=foods[i].c;j--)
            f[j]=max(f[j],f[j-foods[i].c]+foods[i].a-j*foods[i].b);
    */
    for(LL i = 1; i <= n; i++)
        for(LL j = T; j - foods[i].c >= 0; j--)
            f[j] = max(f[j], f[j-foods[i].c] + foods[i].a - j * foods[i].b);
    LL mx=0;
    fo(1,T)
        mx=max(mx,f[i]);
    cout <<mx;
    return 0;
}
