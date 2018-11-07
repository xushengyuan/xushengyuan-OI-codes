//Date:
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n;
int fact(int x)
{
    int ans = 1;
    for (int i = 1; i <= x; i++)
        ans *= i;
    return ans;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    vector<int>data;
    for(int i=0;i<n;i++)
        data.push_back(i);
    int m=fact(n),cot=0;
    for(int i=0;i<m;i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
            if(data[j]==j)
                flag=false;
        if(flag)
            cot++;
        next_permutation(data.begin(),data.end());
    }
    cout<<cot;
    return 0;
}