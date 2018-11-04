//Date:2018/9/29
//OJ:luogu
//Problem:1541
//Solution:DP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 400
#define MAXM 40
#define _DEBUG
using namespace std;
int n,m,cot[5];
int data[MAXN];
int f[MAXM][MAXM][MAXM][MAXM];
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>data[i];
    memset(cot,0,sizeof(cot));
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        cot[t]++;
    }
    f[0][0][0][0]=data[0];
    for(int a=0;a<=cot[1];a++)
        for(int b=0;b<=cot[2];b++)
            for(int c=0;c<=cot[3];c++)
                for(int d=0;d<=cot[4];d++)
                {
                    int length=a+b*2+c*3+d*4;
                    if(a!=0)    
                        f[a][b][c][d]=max(f[a][b][c][d],f[a-1][b][c][d]+data[length]);
                    if(b!=0)    
                        f[a][b][c][d]=max(f[a][b][c][d],f[a][b-1][c][d]+data[length]);
                    if(c!=0)    
                        f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c-1][d]+data[length]);
                    if(d!=0)    
                        f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c][d-1]+data[length]);
                }
    cout<<f[cot[1]][cot[2]][cot[3]][cot[4]];
    return 0;
}