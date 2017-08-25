//Date:2017/8/11
//OJ:luogu
//Problem:2955
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    char tmp[100];
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>tmp;
        if((tmp[strlen(tmp)-1]-'0')%2==0 ||(tmp[strlen(tmp)-1]-'0')==0)
            cout <<"even"<<endl;
        else
            cout <<"odd"<<endl;
    }
    return 0;
}