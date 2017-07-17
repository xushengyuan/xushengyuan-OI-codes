/*
	problem : Luogu 1879
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 23:47
	耗时：1ms
	内存：12320kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 13;
const int S = (1 << N) + 5;
const int MOD = 1e9;

int n, m, ts;
int a[N][N], s[N];
int f[N][S], g[S];

int work()
{
	ts = 1 << m;

	for(int i = 0; i < ts; ++ i)
		g[i] = ((i & (i<<1)) == 0) && ((i & (i>>1)) == 0);

	f[0][0] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < ts; ++ j)
			if(g[j] && ((j & s[i]) == j))
			for(int k = 0; k < ts; ++ k)
				if((k & j) == 0)
					f[i][j] = (f[i][j] + f[i-1][k]) % MOD;

	int ans = 0;
	for(int j = 0; j < ts; ++ j) 
		ans = (ans + f[n][j]) % MOD;

	return ans;
}


int main()
{

	cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j) cin >> a[i][j];

	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			s[i] = (s[i] << 1) + a[i][j];

	cout << work() << endl;

	return 0;
}
