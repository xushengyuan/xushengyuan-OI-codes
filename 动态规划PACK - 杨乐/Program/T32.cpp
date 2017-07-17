/*
	problem : Luogu 1896
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 23:57
	耗时：58ms
	内存：19746kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 10;
const int S = (1 << N) + 5;

int n, m, k, ts;
int cnt[S], g[S], h[S];
LL f[N][S][N*N];

int main()
{

	cin >> n >> k;

	ts = 1 << n;
	for(int i = 0; i < ts; ++ i)
	{
		g[i] = ((i & (i<<1)) == 0) && ((i & (i>>1)) == 0);
		h[i] = i | (i << 1) | (i >> 1);
		cnt[i] = cnt[i>>1] + (i&1);
	}

	f[0][0][0] = 1;

	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < ts; ++ j)
			for(int l = 0; l <= k; ++ l) if(f[i][j][l])
				for(int p = 0; p < ts; ++ p) 
					if(g[p] && ((h[p] & j) == 0))
						f[i+1][p][l + cnt[p]] += f[i][j][l];

	LL ans = 0;
	for(int j = 0; j < ts; ++ j) ans += f[n][j][k];

	cout << ans << endl;

	return 0;
}
