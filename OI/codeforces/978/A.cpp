//Date:2018/5/19
//OJ:Codeforces
//Problem:978-A
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
#define MAXN 50
using namespace std;
int n;
int data[MAXN];
set<int>P;
vector<int>arr;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)   
        cin>>data[i];
    for(int i=n-1;i>=0;i--)
        if(P.empty() || P.find(data[i])==P.end())
        {
            P.insert(data[i]);
            arr.push_back(data[i]);
        }
    cout<<P.size()<<endl;
    for(int i=P.size()-1;i>=0;i--)
        cout<<arr[i]<<' ';
    return 0;
}