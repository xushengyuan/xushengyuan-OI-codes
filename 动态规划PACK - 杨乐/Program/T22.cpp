/*
	problem : Luogu 1063
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 20:29
	耗时：424ms
	内存：12042kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 205;

int n;
int a[N];
int f[N][N];

int work(int *a)
{
	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= n; ++ j) f[i][j] = 0;

	for(int s = 2; s <= n; ++ s)
		for(int i = 0; i + s <= n; ++ i)
		{
			int j = i + s;
			for(int k = i + 1; k < j; ++ k)
				f[i][j] = max(f[i][j], 
					f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
		}

	return f[0][n];
}


int main()
{

	cin >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> a[i], a[i+n] = a[i];

	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = max(ans, work(a + i));

	cout << ans << endl;

	return 0;
}
