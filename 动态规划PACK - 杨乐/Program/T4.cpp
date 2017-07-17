/*
	Problem: Luogu P1216
	Solution: 动态规划（逆推法）
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-28 21:35
	耗时：323ms
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
	for(int i = 0; i < n; ++ i)
	{
		f[i][0] = f[i-1][0] + a[i][0];
		f[i][i] = f[i-1][i-1] + a[i][i];

		for(int j = 1; j < i; ++ j)
			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
	}
		
	ans = 0;
	for(int i = 0; i < n; ++ i)
		ans = max(ans, f[n-1][i]);
	printf("%d\n", ans);

	return 0;
}


