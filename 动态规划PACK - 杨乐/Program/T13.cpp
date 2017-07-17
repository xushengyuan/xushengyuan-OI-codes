/*
	problem : Luogu 1091
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 10:49
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
	cin >> n;

	for(int i = 1; i <= n; ++ i) cin >> a[i], f[i] = g[i] = 1;

	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j < i; ++ j)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);

	for(int i = n; i; -- i)
		for(int j = n; j > i; -- j)
			if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);

	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = max(ans, f[i] + g[i] - 1);

	cout << n - ans << endl;

	return 0;
}
