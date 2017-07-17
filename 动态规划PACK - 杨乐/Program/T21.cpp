/*
	problem : Luogu 1043
	solution : DP

	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 20:18
	耗时：43ms
	内存：12050kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 105;
const LL INF = 1e10;

int n, m;
int a[N], s[N];

LL f[N][N], g[N][N];
LL amin, amax;

void work(int *a)
{
	s[0] = 0;
	for(int i = 1; i <= n; ++ i) s[i] = s[i-1] + a[i];

	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j) 
			f[i][j] = 0, g[i][j] = INF;

	f[0][0] = g[0][0] = 1;
	
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			for(int k = 0; k < i; ++ k)
			{
				f[i][j] = max(f[i][j], f[k][j-1] * (((s[i] - s[k]) % 10 + 10) % 10));
				
				if(g[k][j-1] != INF)
					g[i][j] = min(g[i][j], g[k][j-1] * (((s[i] - s[k]) % 10 + 10) % 10));
			}
				

	amax = max(amax, f[n][m]);
	amin = min(amin, g[n][m]);
}


int main()
{

	cin >> n >> m;

	for(int i = 1; i <= n; ++ i)
		cin >> a[i], a[n+i] = a[i];

	amax = 0;
	amin = INF;

	for(int i = 1; i <= n; ++ i) work(a + i - 1);

	cout << amin << endl << amax << endl;

	return 0;
}
