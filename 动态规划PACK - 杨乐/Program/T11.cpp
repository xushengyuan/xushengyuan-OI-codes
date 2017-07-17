/*
	problem : Luogu 1004
	solution : DP
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 10:12
	耗时：0ms
	内存：11921kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;

int n;
int a[N][N];
int f[N][N][N][N];

int main()
{
	cin >> n;

	for(;;)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if(x == 0) break;

		a[x][y] = z;
	}

	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			for(int k = 1; k <= n; ++ k)
				for(int l = 1; l <= n; ++ l)
				{
					int cost = a[i][j] + a[k][l] - a[i][j] * (i == k && j == l);
					f[i][j][k][l] = max
					(
						max(f[i-1][j][k-1][l], f[i-1][j][k][l-1]),
						max(f[i][j-1][k-1][l], f[i][j-1][k][l-1])
					) + cost;
				}

	cout << f[n][n][n][n] << endl;
	return 0;
}
