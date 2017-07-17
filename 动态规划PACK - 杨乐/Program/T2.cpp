/*
	Problem: Luogu P1216
	Solution: 动态规划（顺推法）
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-28 21:31 
	耗时：329ms
	内存：19589kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int n;
int a[N][N];
int f[N][N];
int ans;

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j <= i; ++ j)
			cin >> a[i][j],
			f[i][j] = 0;

	f[0][0] = a[0][0];
	for(int i = 0; i < n - 1; ++ i)
		for(int j = 0; j <= i; ++ j)
		{
			f[i+1][j] = max(f[i+1][j], f[i][j] + a[i+1][j]);
			f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + a[i+1][j+1]);
		}

	ans = 0;
	for(int i = 0; i < n; ++ i)
		ans = max(ans, f[n-1][i]);
	printf("%d\n", ans);

	return 0;
}


