#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
#define N 2005
int dp[N][N];
char str1[N],str2[N];
int b[2005][2005];
int LCSL(int len1,int len2)
{
    int i,j;
    int len=max(len1,len2);
    memset(b,0,sizeof(int));
    for(i=0;i<=len;i++)
    {
        dp[i][0]=0;dp[0][i]=0;
    }
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                b[i][j]=0;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                b[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                b[i][j]=-1;
            }
        }
    }
    return dp[len1][len2];
}
void PrintLCS(int b[][N], char *x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        PrintLCS(b, x, i-1, j-1);
        printf("%c", x[i-1]);
    }
    else if(b[i][j] == 1)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}
int main()
{
    int len1,len2,len=0;
    cin>>str1>>str2;
    len1=strlen(str1);
    len2=strlen(str2);
    len=LCSL(len1,len2);
    cout<<len<<endl;
    PrintLCS(b,str1,len1,len2);
    return 0;
}
