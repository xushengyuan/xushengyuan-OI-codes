//Date:2018/3/3
//OJ:UVa
//Problem:11991
//Solution:STL
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n,m;
map<int,vector<int> >mp;
int main()
{ 
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    while(scanf("%d%d",&n,&m)>0)
    {
        mp.clear();
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            if(mp.count(t)==false)
                mp[t]=vector<int>();
            mp[t].push_back(i+1);
        }
        for(int i=0;i<m;i++)
        {
            int k,v;
            cin>>k>>v;
            if(mp.count(v)==false || mp[v].size()<k)
                cout<<0<<endl;
            else
                cout<<mp[v][k-1]<<endl;
        }
    }
    return 0;
}