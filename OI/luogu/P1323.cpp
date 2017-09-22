//Date:2017/8/27
//OJ:luogu
//Problem:1323
//Solution:Heap
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int k,m;
string int2str(const int int_temp)
{
    string string_temp;
    stringstream stream;
    stream<<int_temp;
    string_temp=stream.str();   //此处也可以用 stream>>string_temp
    return string_temp;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>k>>m;
    int tot=0,t;
    string str;
    q.push(1);
    tot++;
    while(tot<=k)
    {
        t=q.top();
        q.pop();
        q.push(t*2+1);
        q.push(t*4+5);
        tot++;
        cout <<t;
        str+=int2str(t);
    }  
    cout <<endl;
    int len=str.length();
    bool flag=false;
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<len-1;i++)
            if(str[i]<str[i+1])
            {
                str.erase(str.begin()+i);
                flag=true;
                break;
            }
        if(!flag)
        {
            str.erase(str.end());
        }
    }
    cout <<str<<endl;
    return 0;
}