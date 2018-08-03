#include<stdio.h>
#include<string.h>
#define _DEBUG
char word[22][20],temp;
char str_temp[20];
int v[22],a[22][22],link[22][22],n,long_max=0,ge,z;
int sel(char *s,int j,int f)
{
    int i;
    ge=0;
    for(i=j; i<=f; i++)
        str_temp[ge++]=*(s+i);
    str_temp[ge]='\0';
    return 0;
}
int is_link(char *str_a,char *str_b)
{
    int i,flag=1;
    for(i=0;i<strlen(str_b); i++)
        if(str_a[i]!=str_b[i])
            flag=0;
    return flag;
}
int dfs(int si,int len)
{
    int i;
    if (len>long_max)
        long_max=len;
    for(i=1; i<=n; i++)
        if(link[si][i]>0&&v[i]<2)
        {
            v[i]++;
            dfs(i,len+strlen(word[i])-link[si][i]);
            v[i]--;
        }
}
int link_set()
{
    int i,j,k;
    for(i=1; i<=n; i++)
    {
        z=strlen(word[i]);
        for(k=z-1; k>=1; k--)
        {
            sel(word[i],k,z-1);
            for(j=1; j<=n; j++)
                if ((is_link(word[j], str_temp)==1)&&(link[i][j]==0)&&(ge!=strlen(word[i]))&&(ge!=strlen(word[j])))
                    link[i][j]=ge;
        }
    }
    return 0;
}
int    link_fill(int n)
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            link[i][j]=n;
    return 0;
}
int main()
{

    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%s",word[i]);
        v[i]=0;
    }
    link_fill(0);
    link_set();
    memset(str_temp,0,sizeof(str_temp));
    scanf("%s",str_temp);
    temp=str_temp[0];
    for(i=1; i<=n; i++)
        if (word[i][0]==temp)
            link[0][i]=1;
    dfs(0,0);
    printf("%d",long_max+1);
    return 0;
}