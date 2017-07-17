/*
	problem : Luogu 1279
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 19:00
	耗时：878ms
	内存：27218kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005;

int n, m, k;
string p, q;

int f[N][N];

int abs(int x){return x > 0 ? x : -x;}

int work()
{
	f[0][0] = 0;
	for(int i = 1; i <= n; ++ i) f[i][0] = i * k;
	for(int j = 1; j <= m; ++ j) f[0][j] = j * k;

	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
		{
			f[i][j] = min(f[i-1][j], f[i][j-1]) + k;
			f[i][j] = min(f[i][j], f[i-1][j-1] + abs(p[i-1] - q[j-1]));
		}

	return f[n][m];
}


int main()
{

	cin >> p >> q >> k;

	n = p.length();
	m = q.length();

	cout << work() << endl;

	return 0;
}
