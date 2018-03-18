//Date:2018/3/15
//OJ:luogu
//Problem:2548
//Solution:String
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1010
using namespace std;
int n,m;
char str[MAXN][12],t[MAXN][12];
bool flag[MAXN];
void read_word(char *ptr)
{
    int p=0;
    char t;
    t=getchar();
    while(t!=EOF && !islower(t))
        t=getchar();
    while(t!=EOF && islower(t))
    {
        ptr[p++]=t;
        t=getchar();
    }
    ptr[p++]='\0';
    return ;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    memset(flag,0,sizeof(flag));
    cin>>n>>m;
    for(int k=0;k<n;k++)
        read_word(str[k]);
    for(int i=0;i<m-1;i++)
    {
        for(int k=0;k<n;k++)
        {
            read_word(t[k]);
            if(strcmp(str[k],t[k])!=0)
                flag[k]=true;
        }
    }
    for(int k=0;k<n;k++)
        if(flag[k])
            cout<<"* ";
        else
            printf("%s ",t[k]);
    return 0;
}