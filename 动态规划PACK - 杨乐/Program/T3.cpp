/*
	Problem: Luogu P1216
	Solution: 动态规划（逆推法 / 路径自底向上）
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-28 21:38
	耗时：312ms
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

	for(int i = 0; i < n; ++ i)
		f[n-1][i] = a[n-1][i];

	for(int i = n-2; i >= 0; -- i)
		for(int j = 0; j <= i; ++ j)
			f[i][j] = max(f[i+1][j+1], f[i+1][j]) + a[i][j];
		
	ans = f[0][0];
	printf("%d\n", ans);

	return 0;
}


