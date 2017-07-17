/*
	problem : Luogu 1122
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 23:21
	耗时：145ms
	内存：12761kb
*/

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 16005;

int n, m;
int a[N], f[N];

vector<int> e[N];

void dfs(int x, int y = 0)
{
	f[x] = a[x];

	for(unsigned i = 0; i < e[x].size(); ++ i)
	{
		int u = e[x][i];
		if(u == y) continue;

		dfs(u, x);
		if(f[u] >= 0) f[x] += f[u];
	}
}

int main()
{

	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	for(int i = 1, x, y; i < n; ++ i)
	{
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs(1);

	int ans = a[1];
	for(int i = 1; i <= n; ++ i) ans = max(ans, f[i]);
	cout << ans << endl;

	return 0;
}
