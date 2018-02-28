//Date:2018/2/20
//OJ:luogu
//Problem:1449
//Solution:Stack
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    stack<int>st;
    char t;
    int i=0,p=0;
    while((t=getchar())!='@')
    {
        if(isdigit(t))
            p=p*10+t-'0';
        else if(t=='.')
        {
            st.push(p);
            p=0;
        }
        else if(t=='+')
        {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y+x);
        }
        else if(t=='-')
        {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y-x);
        }
        else if(t=='*')
        {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y*x);
        }
        else if(t=='/')
        {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y/x);
        }
    }
    cout<<st.top();
    return 0;
}