//Date:2018/3/5
//OJ:luogu
//Problem:1026
//Solution:DP
//By:xushengyuan
//f[i][j]表示用前i个字母切分为j段时可获得的最大单词数
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 210
#define MOD 1000007
using namespace std;
int p,k,s;
int f[MAXN][MAXN],cot[MAXN][MAXN];
int hashs[10];
string words[10];
char ch[210];
int hash(string str)
{
    int result=0;
    for(int i=0;i<str.len();i++)
        result=(result*97+str[i]+i)%MOD;
    return result;
}
bool check(int x,int l,int r)
{
    string tmp;
    for(int i=l;i<=r;i++)
        tmp.push_back(ch[i]);
    if(hash(tmp)==x)
        return true;
    else
        return false;
}
bool vis[210];
void init()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<s;i++)
        for(int j=0;j<p*20;j++)
        {
            if(vis[j])
                continue;
            int pl=words[i].len;
            
        }
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>p>>k;
    int pp=0;
    for(int i=0;i<p;i++)
        for(int j=0;j<20;j++,pp++)
            cin>>ch[pp];
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cin>>words[i];
        hashs[i]=hash(words[i]);
    }
    init();
    return 0;
}