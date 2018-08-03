//Date:2018/5/19
//OJ:Codeforces
//Problem:978-B
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n;
string str;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>str;
    int cot=0,ans=0;
    for(int i=0;i<str.length();i++)    
    {
        if(str[i]=='x')
        {
            cot++;
            if(cot==3)
            {
                cot--;
                ans++;
            }
        }
        else if(str[i]!='x')
            cot=0;
    }
    cout<<ans<<endl;
    return 0;
}
