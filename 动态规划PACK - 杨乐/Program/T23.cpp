/*
	problem : Luogu 1103
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 20:47
	耗时：37ms
	内存：11929kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
const int INF = 1e9;

int n, k;
int h[N], w[N];
int a[N], b[N];
int f[N][N];

int cmp(int x, int y) { return h[x] < h[y]; }

int abs(int x) { return x > 0 ? x : -x; }

int work()
{
	int m = n - k;

	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			f[i][j] = INF;

	for(int i = 1; i <= n; ++ i) f[i][1] = 0;

	for(int i = 2; i <= n; ++ i)
		for(int j = 2; j <= m; ++ j)
			for(int l = 1; l < i; ++ l)
				f[i][j] = min(f[i][j], f[l][j-1] + abs(a[i] - a[l]));

	int ans = INF;
	for(int i = 1; i <= n; ++ i) ans = min(ans, f[i][m]);

	return ans;
}

int main()
{

	cin >> n >> k;
	for(int i = 1; i <= n; ++ i) cin >> h[i] >> w[i], b[i] = i;

	sort(b + 1, b + n + 1, cmp);

	for(int i = 1; i <= n; ++ i) a[i] = w[b[i]];

	cout << work() << endl;

	return 0;
}
