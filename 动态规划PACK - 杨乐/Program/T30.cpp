/*
	problem : Luogu 2014
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 23:38
	耗时：110ms
	内存：12250kb
*/

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 305;

int n, m, a[N];

vector<int> e[N];

int f[N][N];
int tp[N];

void dfs(int x)
{
	int *dp = f[x];

	for(unsigned i = 0; i < e[x].size(); ++ i)
	{
		int u = e[x][i];
		dfs(u);
		
		for(int j = 0; j <= m; ++ j) tp[j] = 0;
		for(int j = 0; j <= m; ++ j)
			for(int k = 0; j + k <= m; ++ k)
				tp[j + k] = max(tp[j + k], dp[j] + f[u][k]);
		for(int j = 0; j <= m; ++ j) dp[j] = tp[j];
	}

	for(int j = m; j; -- j) dp[j] = dp[j-1] + a[x];
	dp[0] = 0;
}

int main()
{
	freopen("T30.in", "r", stdin);

	cin >> n >> m, ++ m;

	for(int i = 1, fa; i <= n; ++ i) 
		cin >> fa >> a[i], e[fa].push_back(i);

	dfs(0);

	cout << f[0][m] << endl;

	return 0;
}
