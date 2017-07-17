/*
	Problem: Luogu P1216
	Solution: 记忆化搜索

	评测结果：Unaccepted 
	得分：　　77
	提交时间：2017-06-28 21:18 耗时：60ms
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

void dfs(int x, int y, int val)
{
	val += a[x][y];

	if(val <= f[x][y]) return;
	f[x][y] = val;

	if(x == n-1)
	{
		if(val > ans) ans = val;
		return;
	}

	dfs(x+1, y, val);
	dfs(x+1, y+1, val);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j <= i; ++ j)
			cin >> a[i][j],
			f[i][j] = -1;

	ans = 0;
	dfs(0, 0, 0);
	cout << ans << endl;

	return 0;
}


