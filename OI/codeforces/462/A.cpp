//Date:2018/2/14
//OJ:Codeforces
//Problem:462 A
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n,m;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;   
    int _max1=-0x7fffffff,_max2=-0x7fffffff;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    int p=arr[1];
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        _max1=max(t,_max1);
    }
    cout<<p*_max1;
    return 0;
}