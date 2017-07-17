/*
	Problem : Luogu 1048 采药
	Solution : 记忆化搜索
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-28 22:01
	耗时：2120ms
	内存：15742kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int t, n;
int v[N], w[N];

int f[N][N];
int ans;

void dfs(int t, int x, int val)
{
	if(val <= f[t][x]) return;

	f[t][x] = val;

	if(x == n)
	{
		if(val > ans) ans = val;
		return;
	}

	dfs(t, x+1, val);
	if(t >= w[x]) dfs(t - w[x], x+1, val + v[x]);
}

int main()
{
	cin >> t >> n;

	for(int i = 0; i < n; ++ i)
		cin >> w[i] >> v[i];

	for(int i = 0; i < n; ++ i)
		for(int j = 0; j <= t; ++ j)
			f[j][i] = -1;

	ans = 0;
	dfs(t, 0, 0);

	cout << ans << endl;

	return 0;
}


