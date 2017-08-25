//Date:2017/8/9
//OJ:luogu
//Problem:1540
//By:xushengyuan
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int m, n;
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    int result=0;
    cin >>m>>n;
    int t;
    vector<int> dict;
    for(int i=0;i<n;i++)
    {
        cin >>t;
        if(find(dict.begin(),dict.end(),t)==dict.end())
        {
            result++;
            dict.push_back(t);
            if(dict.size()>m)
                dict.erase(dict.begin());
        }
    }
    cout <<result;
    return 0;
}