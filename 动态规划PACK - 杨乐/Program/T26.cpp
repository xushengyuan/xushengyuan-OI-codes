/*
	problem : Luogu 1057
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 22:28
	耗时：0ms
	内存：11890kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 35;

int n, m;
LL f[N][N];

LL work()
{
	f[0][1] = 1;

	for(int i = 1; i <= m; ++ i)
	{
		f[i][1] = f[i-1][2] + f[i-1][n];
		f[i][n] = f[i-1][n-1] + f[i-1][1];

		for(int j = 2; j < n; ++ j)
			f[i][j] = f[i-1][j-1] + f[i-1][j+1];
	}

	return f[m][1];
}


int main()
{

	cin >> n >> m;

	cout << work() << endl;

	return 0;
}
