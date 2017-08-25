#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int m[10][10];
int f[10][10][10][10];
int main()
{
    memset(m,0,sizeof(m));
    memset(f,0,sizeof(f));
    int i,j,a,b;
    cin>>n;
    int x=1, y, z;
    while(x!=0)
    {
		cin >> x >> y >> z;
		m[x][y] = z;
    }
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            for (int a = 1; a <=n; a++)
                for (int b = 1; b <=n; b++)
                {
                    f[i][j][a][b] = max(max(f[i-1][j][a-1][b], f[i-1][j][a][b-1]),
                                        max(f[i][j-1][a-1][b], f[i][j-1][a][b-1]))+
                                         m[i][j] + m[a][b] - m[i][j] * (i == a && j == b);
                    //cout <<f[i][j][a][b]<<' ';
                }
    cout<<f[n][n][n][n]<<endl;
    /*for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
            cout <<m[i][j]<<' ';
        cout <<endl;
    }*/
    //system("pause");
    return 0;
}