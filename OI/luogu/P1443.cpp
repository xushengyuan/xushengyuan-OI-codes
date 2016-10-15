#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int d_x[40000],d_y[4000],a[202][202],v[202][202];
int move[8][2]= {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m,p_x,p_y;
    int p,tail,i,j;
    scanf("%d%d%d%d",&n,&m,&p_x,&p_y);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            a[i][j]=0;
            v[i][j]=0;
        }
    }
    int x,y,num;
    p=0;
    tail=1;
    d_x[0]=p_x-1;
    d_y[0]=p_y-1;
    a[p_x-1][p_y-1]=-1;
    v[p_x-1][p_y-1]=-1;
    while(p<tail)
    {
        for(i=0; i<8; i++)
        {
            x=d_x[p]+move[i][0];
            y=d_y[p]+move[i][1];
            if(x>=0 && y>=0 && x<n && y<m && v[x][y]==0 )
            {
                v[x][y]=-1;
                a[x][y]=a[d_x[p]][d_y[p]]+1;
                d_x[tail]=x;
                d_y[tail]=y;
                tail++;
            }
        }
        p++;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%-5d",a[i][j]-1);
        printf("\n");
    }
    return 0;
}
