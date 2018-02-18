//Date:2018/2/18
//OJ:luogu
//Problem:1010
//Solution:Bit
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n;
string dfs(int x)
{
    string str="";
    if(x==0)
        return string("0");
    int i=0;
    do
    {
        if(x&1==1)
        {
            if(i==1)
            {
                if(str=="")
                    str="2"+str;
                else
                    str="2+"+str;
            }
            else
            {
                if(str=="")
                    str="2("+dfs(i)+")"+str;
                else
                    str="2("+dfs(i)+")+"+str;
            }
        }
    }
    while(i++,x>>=1);
    return str;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    cout<<dfs(n);
    return 0;
}