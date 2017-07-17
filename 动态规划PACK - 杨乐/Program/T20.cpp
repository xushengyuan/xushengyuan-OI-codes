/*
	problem : Luogu 1018
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 19:53
	耗时：0ms
	内存：27218kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005;

int n, k;
string s;

int f[N][N];

int val(int x, int y)
{
	-- x;

	int r = 0;
	for(int i = x; i < y; ++ i)
		r = r * 10 + s[i] - '0';

	return r;
}

void work()
{
	++ k;

	f[0][0] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= k; ++ j)
			for(int l = 0; l < i; ++ l)
				f[i][j] = max(f[i][j], f[l][j-1] * val(l+1, i));

	cout << f[n][k] << endl;
}


int main()
{

	cin >> n >> k >> s;

	work();

	return 0;
}
