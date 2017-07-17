/*
	problem : Luogu 1472
	solution : DP
	
	work1:
	评测结果：Unaccepted 
	得分：　　84
	提交时间：2017-06-30 23:08
	耗时：3093ms
	内存：12042kb

	work2:
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 23:13
	耗时：429ms
	内存：12203kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 205;
const int MOD = 9901;

int n, m;
int f[N][N];
int g[N][N];

int work1()
{
	f[1][1] = 1;

	for(int i = 3; i <= n; ++ i)
		for(int j = 2; j <= m; ++ j)
			for(int k = 1; k < i; ++ k)
			{
				for(int l = 1; l < j - 1; ++ l)
					f[i][j] = (f[i][j] + f[k][j-1] * f[i-k-1][l] * 2 % MOD) % MOD;
				f[i][j] = (f[i][j] + f[k][j-1] * f[i-k-1][j-1] % MOD) % MOD;
			}

	return f[n][m];
}

int work2()
{
	f[1][1] = g[1][1] = 1;

	for(int j = 2; j <= m; ++ j) g[1][j] = 1;

	for(int i = 3; i <= n; ++ i)
		for(int j = 2; j <= m; ++ j)
		{
			for(int k = 1; k < i; ++ k)
			{
				f[i][j] = (f[i][j] + f[k][j-1] * g[i-k-1][j-2] * 2 % MOD) % MOD;
				f[i][j] = (f[i][j] + f[k][j-1] * f[i-k-1][j-1] % MOD) % MOD;
			}
			g[i][j] = (g[i][j-1] + f[i][j]) % MOD;
		}

	return f[n][m];
}


int main()
{

	cin >> n >> m;

	cout << work2() << endl;

	return 0;
}
