//Date:2017/8/14
//OJ:luogu
//Problem:1341
//Solution:Euler Path
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 52
using namespace std;
bool g[MAXN][MAXN]={false};
int du[MAXN]={0};
int n;
stack<int> q;
inline int char2int(char x)
{
    if(x >= 'a' && x <= 'z')
        return x-'a'+26;
    else if(x >= 'A' && x <= 'Z')
        return x-'A';
}
inline char int2char(int x)
{
    if(x >= 0 && x<=25)
        return x+'A';
    else if(x >= 26 && x<=51)
        return x-26+'a';
}
inline void connect(char x,char y)
{
    int a=char2int(x),b=char2int(y);
    g[a][b]=true;
    g[b][a]=true;
    //cout <<a<<' '<<b<<endl;
    du[a]++;
    du[b]++;
    return;
}
void dfs(int p)
{
    //cout <<p<<"/"<<endl;
    for(int i=0;i<52;i++)
        if(g[p][i])
        {
            g[p][i]=false;
            g[i][p]=false;
            dfs(i);
        }
    q.push(p);
}
int main()
{
    /*#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif*/
    cin >>n;
    char t;
    for(int i=0;i<n;i++)
    {
        t=getchar();
        while(!isalpha(t))
            t=getchar();
        connect(t,getchar());
    }
    int odd=0; 
    for(int i=0;i<52;i++)
        if(du[i]&1==1)
            odd++;
    int p=0x7fffffff;
    /*for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
            cout <<g[i][j]<<' ';
        cout <<endl;
    }*/
    //cout <<'|'<<odd<<endl;
    if(odd==0 || odd==2)
    {
        if(odd==0)
        {
            for(int i=0;i<52;i++)
                if(du[i]!=0)
                    p=min(p,i);
        }
        else if(odd==2)
        {
            for(int i=0;i<52;i++)
                if(du[i]&1==1)
                    p=min(p,i);
        }
        //cout <<'|'<<p<<endl;
        dfs(p);
        //cout <<q.size()<<'|'<<endl;
        if(q.size()!=n+1)
            cout <<"No Solution"; 
        else
            while(!q.empty())
            {
                cout <<int2char(q.top());
                q.pop();
            }
    }   
    else
        cout <<"No Solution"; 
    return 0;
}