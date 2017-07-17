#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    string in;
    int p=0;
    cin >> in;
    p=in.length()-1;
    bool flag=true;
    stack<char> sta;
    while(p>=0)
    {
        //cout <<in<<endl;
        if(in.at(p)==')')
            sta.push(')');
        if(in.at(p)=='(' && !sta.empty())
            sta.pop();
        else if(in.at(p)=='(' &&sta.empty())
        {
            flag=false;
            break;
        }
        p--;
    }    
    if(!sta.empty())
        flag=false;
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}