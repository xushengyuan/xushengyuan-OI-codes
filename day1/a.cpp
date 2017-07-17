#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
struct pos
{
    int i,j;
};
queue<pos> q;
int sum=0,result=0;
char source[10][10];
void swap(char *a,char *b);
int check();
int fun(char t[10][10])
{
    int t_check=0,s=0;
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            s=0;
            t_check=0;
            //j+1 right
            if(t[i][j]!=t[i][j+1])
            {
                memcpy(source,t,10*10);
                swap(&t[i][j],&t[i][j+1]);
                do
                {
                    t_check=check();
                    s+=t_check;
                    //cout <<t_check<<endl;
                } while(t_check!=0);
                if(s==sum)
                    result++;
                else if(s>sum)
                {
                    sum=s;
                    result=1;
                }
            }
            //i+1 down
            if(t[i][j]!=t[i+1][j])
            {
                memcpy(source,t,10*10);
                swap(&t[i][j],&t[i+1][j]);
                do
                {
                    t_check=check();
                    s+=t_check;
                } while(t_check!=0);
                if(s==sum)
                    result++;
                else if(s>sum)
                {
                    sum=s;
                    result=1;
                }
            }
        }
    }
}
int check()
{
    int flag;
    char t;
    int s=0;
    pos t_pos;
    //
    s=0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            /*printf("\n");
            for(int z=1;z<=8;z++)
            {
                for(int v=1;v<=8;v++)
                    printf("%c",source[z][v]);
                printf("\n");
            }*/
            flag=0;
            t=source[i][j];
            if(t==' ') continue;
            for (int k = 0; k < 7-i; k++)
            {
                if(source[i][j+k]=='M')
                {
                    flag++;
                    continue;
                }
                else if(source[i][j+k]==t||t=='M')
                {
                    if(t=='M')
                        t=source[i][j+k];
                    flag++;
                    continue;
                }
                break;
            }
            if(flag>=3)
                if(source[i][j]=='#')
                {
                    for (int a = 0; a < flag; a++)
                    {
                        t_pos.i=i;
                        t_pos.j=j+a;
                        s++;
                        q.push(t_pos);
                    }
                    /*memset(source[i-1][j+k-1],' ',flag+2);
                    memset(source[i][j+k-1],' ',flag+2);
                    memset(source[i+1][j+k-1],' ',flag+2);*/
                }
                else
                {
                    memset(&source[i][j],' ',flag);
                    s+=flag;
                }
        }
    }
    int it,jt;
    while(!q.empty())
    {
        t_pos=q.back();
        q.pop();
        it=t_pos.i;
        jt=t_pos.j;
        source[it][jt]=' ';
        for (int a = -1; a <= 1; a++)
        {
            for (int b = -1; b <= 1; b++)
            {
                if(source[it+a][jt+b]=='#')
                {
                    t_pos.i=it+a;
                    t_pos.j=jt;
                    s++;
                    q.push(t_pos);
                }
                else if(source[it+a][jt+b]!=' ')
                {
                    source[it+a][jt+b]=' ';
                    s++;
                }
            }
        }
    }
    for (int j = 1; j <= 8; j++)
    {
        for (int i = 1; i <= 6; i++)
        {
            flag=0;
            t=source[i][j];
            for (int k = 0; k < 7-i; k++)
            {
                if(source[i+k][j]=='M')
                {
                    if(t=='M')
                        t=source[i+k+1][j];
                    flag++;
                }
                else if(source[i+k][j]==t )
                {
                    flag++;
                }
            }
            if(flag>=3)
                if(source[i][j]=='#')
                {
                    for (int k = 0; k < flag+2; k++)
                        if(source[i+k-1][j-1]!=' ')
                            {
                                s++;
                                source[i+k-1][j-1]=' ';
                            }
                    for (int k = 0; k < flag; k++)
                        if(source[i+k-1][j]!=' ')
                            {
                                s++;
                                source[i+k-1][j]=' ';
                            }
                    for (int k = 0; k < flag; k++)
                        if(source[i+k-1][j+1]!=' ')
                            {
                                s++;
                                source[i+k-1][j+1]=' ';
                            }
                }
                else
                {
                    for (int k = 0; k < flag; k++)
                        source[i+k][j]=' ';
                }
        }
    }
    int k;
    for (int j = 1; j <= 8; j++)
    {
        for (int i = 8; i>1; i--)
        {
            if(source[i][j]==' ')
            {
                k=0;
                while(source[i-k][j]==' ' && k<i)
                    k++;
                if(k!=i)
                {
                    swap(&source[i-k][j],&source[i][j]);
                    //cout<<'|';
                }
            }
        }
    }
    return s;
}
void swap(char *a,char *b)
{
    char t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}
int main()
{
    //freopen("in.txt","r",stdin);
    char in[10][10];
    char tmp[10];
    for (int i = 1; i <= 8; i++)
    {
        scanf("%s",tmp);
        printf("%s\n",tmp);
        for (int j = 1; j <= 8; j++)
            in[i][j]=tmp[j-1];
    }
    fun(in);
    cout <<sum<<' '<<result<<endl;
    system("pause");
}