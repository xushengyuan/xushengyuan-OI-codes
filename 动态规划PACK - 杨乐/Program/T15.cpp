/*
	problem : Luogu 1474
	solution : DP
	
	work1:
	评测结果：Unaccepted (TLE)
	得分：　　93
	提交时间：2017-06-30 18:44 
	耗时：507ms
	内存：14250kb

	work2:
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 18:45
	耗时：0ms
	内存：14250kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int V = 30;
const int N = 10005;

typedef long long LL;

int v, n;
int a[V];
LL f[V][N], g[N];

LL work1()
{
	f[0][0] = 1;
	for(int i = 1; i <= v; ++ i)
		for(int j = 0; j <= n; ++ j)
			for(int k = 0; k <= j / a[i]; ++ k)
				f[i][j] += f[i-1][j - a[i]*k];

	return f[v][n];
}

LL work2()
{
	g[0] = 1;
	for(int i = 1; i <= v; ++ i)
		for(int j = a[i]; j <= n; ++ j)
			g[j] += g[j - a[i]];

	return g[n];
}

int main()
{

	cin >> v >> n;
	for(int i = 1; i <= v; ++ i) cin >> a[i];

	LL ans1 = work1();
	LL ans2 = work2();

	cout << ans1 << endl;
	cout << ans2 << endl;

	return 0;
}
