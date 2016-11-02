#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int f[52][52][52][52];
int data[52][52];
int m,n;
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    cin>>m>>n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            cin>>data[i][j];
    int i1,i2,j1,j2;
    f[1][2][2][1]=data[1][2]+data[2][1];
    for(i1=1;i1<=m;i1++)
        for(j1=1;j1<=n;j1++)
            for(i2=1;i2<=m;i2++)
                for(j2=1;j2<=n;j2++)
                {
                    if((i1!=i2||j1!=j2))
                    { 
                        f[i1][j1][i2][j2]=max(f[i1][j1][i2][j2],f[i1-1][j1][i2-1][j2]+data[i1][j1]+data[i2][j2]);
                        f[i1][j1][i2][j2]=max(f[i1][j1][i2][j2],f[i1-1][j1][i2][j2-1]+data[i1][j1]+data[i2][j2]);
                        f[i1][j1][i2][j2]=max(f[i1][j1][i2][j2],f[i1][j1-1][i2-1][j2]+data[i1][j1]+data[i2][j2]);
                        f[i1][j1][i2][j2]=max(f[i1][j1][i2][j2],f[i1][j1-1][i2][j2-1]+data[i1][j1]+data[i2][j2]);
                    }
                }
    cout<<f[m][n-1][m-1][n];
    return 0;
}