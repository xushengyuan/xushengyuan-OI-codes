//Date:2018/2/16
//OJ:Codeforces
//Problem:EDU 38 A
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n;
string str;
bool is(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||ch=='y')
        return true;
    else
        return false;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    cin>>str;
    int len=n;
    bool flag=false;
    putchar(str[0]);
    for(int i=1;i<len;i++)
    {

        if(!(is(str[i-1])&&is(str[i])))
        {
            putchar(str[i]);
        }
    }
    return 0;
}