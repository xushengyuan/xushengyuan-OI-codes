/*
	problem : Luogu 1466
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 18:38
	耗时：0ms
	内存：42570kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005;

typedef long long LL;

int n, m;
LL f[N][N];
LL g[N];

LL work1(int n)
{
	m = (1 + n) * n / 2;
	if(m & 1) return 0;
	m /= 2;

	f[1][0] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j)
		{
			f[i+1][j] += f[i][j];
			if(i + j <= m) f[i+1][i+j] += f[i][j];
		}

	return f[n+1][m];
}

LL work2(int n)
{
	m = (1 + n) * n / 2;
	if(m & 1) return 0;
	m /= 2;

	f[0][0] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j)
		{
			f[i][j] = f[i-1][j];
			if(j >= i) f[i][j] += f[i-1][j-i];
		}

	return f[n][m];
}

LL work3(int n)
{
	m = (1 + n) * n / 2;
	if(m & 1) return 0;
	m /= 2;

	g[0] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = m; j >= i; -- j)
			g[j] += g[j-i];

	return g[m];
}

int main()
{

	cin >> n;

	LL ans1 = work1(n) / 2;
	LL ans2 = work2(n) / 2;
	LL ans3 = work3(n) / 2;

	if(ans1 == ans2 && ans2 == ans3)
		cout << ans1 << endl;
	else cout << -1 << endl;

	return 0;
}
