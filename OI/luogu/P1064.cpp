//Date:2017/8/10
//OJ:luogu
//Problem:1064
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int f[3300]={0},v[60],w[60],child[60][3],child_n[60]={0};
int n,m;
bool ischild[60]={false};
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin >>n>>m;
    n/=10;
    for(int i=0;i<m;i++)
    {
        cin >>v[i]>>w[i]>>t;
        v[i]/=10;
        if(t!=0)
        {
            child[t-1][child_n[t-1]++]=i;
            ischild[i]=true;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(ischild[i]) continue;
        for(int j=n;j>=v[i];j--)   
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]*v[i]);

            if(child_n[i]>0 && j>=v[i]+v[child[i][0]])
                f[j]=max(
                f[j],
                f[j-v[i]-v[child[i][0]]]+
                w[i]*v[i]+
                w[child[i][0]]*v[child[i][0]]);
            
            if(child_n[i]>1 && j>=v[i]+v[child[i][1]])
                f[j]=max(
                f[j],
                f[j-v[i]-v[child[i][1]]]+
                w[i]*v[i]+
                w[child[i][1]]*v[child[i][1]]);

            if(child_n[i]>1 && j>=v[i]+v[child[i][0]]+v[child[i][1]])
                f[j]=max(
                f[j],
                f[j-v[i]-v[child[i][0]]-v[child[i][1]]]+
                w[i]*v[i]+
                w[child[i][0]]*v[child[i][0]]+
                w[child[i][1]]*v[child[i][1]]);
        }    
    }
    int mx=-1;
    for(int i=1;i<=n;i++)
        mx=max(mx,f[i]);
    cout <<mx*10;
    return 0;
}