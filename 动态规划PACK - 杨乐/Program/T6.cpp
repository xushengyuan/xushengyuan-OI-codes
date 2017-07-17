/*
	Problem : Luogu 1048 采药
	Solution : DP（顺推）
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-28 22:11
	耗时：7ms
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


int main()
{
	cin >> t >> n;

	for(int i = 0; i < n; ++ i)
		cin >> w[i] >> v[i];

	for(int i = 0; i < n; ++ i)
		for(int j = 0; j <= t; ++ j)
		{
			f[i+1][j] = max(f[i+1][j], f[i][j]);

			if(j + w[i] <= t)
			f[i+1][j+w[i]] = max(f[i+1][j+w[i]], f[i][j]+v[i]);
		}

	ans = f[n][t];
	cout << ans << endl;

	return 0;
}


