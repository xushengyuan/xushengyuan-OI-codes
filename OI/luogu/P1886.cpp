//Date:2017/9/2
//OJ:luogu
//Problem:1886
//Solution:deque
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1000100
using namespace std;
deque< pair<int,int> > q_max;
deque< pair<int,int> > q_min;
int n,k;
int data[MAXN];
int maxs[MAXN];
bool flag=false;
int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t)&& t!='-')
        t=getchar();
    if(t=='-')
        flag=true;
    t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    if(flag)
        t-=0;
    return result;
}
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    cin >>n>>k;   
    for(int i=0;i<n;i++)
        data[i]=read_int();
    for(int i=0;i<n-k;i++) 
    {
            if(!q_min.empty() &&q_max.front().second==data[i-k])
                q_max.pop_front();
            if(!q_max.empty() &&q_min.front().second==data[i-k])
                q_min.pop_front();

        int j=i;
            while(!q_min.empty() && q_min.back().first>=data[j])
                q_min.pop_back();
            q_min.push_back(make_pair(data[j],j));
            while(!q_max.empty() &&q_max.back().first<=data[j])
                q_max.pop_back();
            q_max.push_back(make_pair(data[j],j));
            maxs[i]=q_max.front().first;
            cout <<q_min.front().first<<' ';
    }
    cout <<endl;
    for(int i=0;i<n-k;i++)
        cout <<maxs[i]<<' ';
    cout <<endl;
    return 0;
}