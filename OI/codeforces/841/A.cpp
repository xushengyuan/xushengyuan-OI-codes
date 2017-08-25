//Date:2017/8/18
//OJ:codeforces
//Problem:841-A
//Solution:None
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
char ch[MAXN];
int n,k;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >>n>>k;
    int count[127]={0};
    for(int i=0;i<n;i++)
    {
        ch[i]=getchar();
        while(!isalpha(ch[i]))
            ch[i]=getchar();
        count[ch[i]]++;
    }
    for(int i='a';i<='z';i++)
        if(count[i]>k)
        {
            cout <<"NO"<<endl;
            return 0;
        }
    cout <<"YES"<<endl;
    return 0;
}