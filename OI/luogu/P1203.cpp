//Date:2018/8/2
//OJ:luogu
//Problem:1203
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 700
#define _DEBUG
using namespace std;
int n;
string data;
int cot[MAXN],p=0;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int _max=2;
    cin>>n;
    cin>>data;
    data=data+data;
    for(int i=0;i<data.length();i++)
    {
        char cor1='0',cor2='0';
        int cnt1=0,cnt2=0;
        int p=i;
        while(p>=0 && (cor1=='0'||data[p]==cor1||data[p]=='w'))
        {
            cnt1++;
            if(cor1=='0'&&data[p]!='w')
                cor1=data[p];
            p--;
        }
        p=i+1;
        while(p<data.length() && (cor2=='0'||data[p]==cor2||data[p]=='w'))
        {
            cnt2++;
            if(cor2=='0'&&data[p]!='w')
                cor2=data[p];
            p++;
        }
         _max=max(_max,cnt1+cnt2);
    }
    cout<<min(_max,n);
    return 0;
}