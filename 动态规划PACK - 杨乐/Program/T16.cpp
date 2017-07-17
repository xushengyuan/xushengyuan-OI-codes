/*
	problem : Luogu 1439
	solution : DP
	
	work1:
	评测结果：Unaccepted (RE)
	得分：　　50
	提交时间：2017-06-30 18:51
	耗时：37ms
	内存：15742kb
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int n;
int p[N], q[N];
int f[N][N];

int work1()
{
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
		{
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(p[i] == q[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
		}
	return f[n][n];
}


int main()
{

	cin >> n;

	for(int i = 1; i <= n; ++ i) cin >> p[i];
	for(int i = 1; i <= n; ++ i) cin >> q[i];

	cout << work1() << endl;

	return 0;
}
