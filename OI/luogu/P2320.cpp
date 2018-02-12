//Date:2018/2/12
//OJ:luogu
//Problem:2320
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int m;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>m;
    if(m==5)
    {
        cout<<3<<endl<<"1 1 3"<<endl;
        return 0;
    }
    int sum=0,tmp=1,ans=0;
    vector<int>arr;
    while (sum+tmp<=m)
    {
        ans++;
        sum+=tmp;
        arr.push_back(tmp);
        tmp*=2;
    }
    if(sum!=m&&sum+tmp>m)
    {
        int t=m-sum;
        if(t==*arr.end())
        {
            arr.end()--;
            arr.push_back(t+1);
        }
        else
        {
            arr.push_back(t);
        }
    }
    sort(arr.begin(),arr.end());
    cout<<arr.size()<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<' ';
    return 0;
}