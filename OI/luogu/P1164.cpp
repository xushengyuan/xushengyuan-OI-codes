#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,plan_ans=0;
int p[105];
void dfs(int num,int money)
{
    if(money==0)
    {
        plan_ans++;
        return ;
    }
    if(num<=0||money<0)
        return ;
    dfs(num-1,money);
    dfs(num-1,money-p[num]);
    return ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>p[i];
    dfs(n,m);
    cout<<plan_ans;
    return 0;
}