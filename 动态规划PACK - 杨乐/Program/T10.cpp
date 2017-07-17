/*
	Problem : Luogu 1048 采药
	Solution : DP（逆推，压缩状态）
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-28 22:47
	耗时：5ms
	内存：11894kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int t, n;
int v[N], w[N];

int f[N];
int ans;

int main()
{
	cin >> t >> n;

	for(int i = 1; i <= n; ++ i)
		cin >> w[i] >> v[i];

	for(int i = 1; i <= n; ++ i)
		for(int j = t; j >= 0; -- j) // !!!
		{
			// f[i][j] = f[i-1][j]; -> f[j] = f[j]
			//if(j >= w[i]) f[i][j] = max(f[i][j], f[i-1][j-w[i]] + v[i]);
			if(j >= w[i]) f[j] = max(f[j], f[j - w[i]] + v[i]);
		}

	ans = 0;
	for(int i = 0; i <= t; ++ i) ans = max(ans, f[i]);
	cout << ans << endl;

	return 0;
}


