/*
	problem : Luogu 1020
	solution : DP
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 10:37
	耗时：0ms
	内存：11894kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int n;
int a[N];
int f[N], g[N];

int main()
{
	freopen("T12.in", "r", stdin);

	n = 0;

	while(!cin.eof()) cin >> a[++n];
	-- n;

	f[0] = 0;

	int ansf = 0, ansg = 0;

	for(int i = 1; i <= n; ++ i)
	{
		f[i] = 0;
		for(int j = 1; j < i; ++ j)
			if(a[j] > a[i]) f[i] = max(f[i], f[j]);
			else g[i] = max(g[i], g[j]);
		++ f[i], ++ g[i];

		ansf = max(ansf, f[i]);
		ansg = max(ansg, g[i]);
	}

	cout << ansf << endl << ansg << endl;

	return 0;
}
