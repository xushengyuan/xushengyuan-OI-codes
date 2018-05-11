//Date:2018/4/10
//OJ:UVa
//Problem:11292
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 20010
using namespace std;
int dataA[MAXN],dataB[MAXN];
int m,n;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    while(n!=0 && m!=0)
    {
        int p=0,sum=0;
        for(int i=0;i<n;i++)       
            cin>>dataA[i];
        for(int i=0;i<m;i++)
            cin>>dataB[i];
        sort(dataA,dataA+n);
        sort(dataB,dataB+m);
        for(int i=0;i<m;i++)
            if(dataA[p] <=dataB[i])
            {
                sum+=dataB[i];
                p++;
                if(p>=n)
                    break;
            }
        if(p<n)
            cout<<"Loowater is doomed!"<<endl;
        else
            cout<<sum<<endl;
        cin>>n>>m;
    }
    return 0;
}