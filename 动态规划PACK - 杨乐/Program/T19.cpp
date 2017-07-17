/*
	problem : Luogu 2734
	solution : DP
	
	评测结果：Accepted 
	得分：　100
	提交时间：2017-06-30 19:12 
	耗时：0ms
	内存：27234kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005;

int n;
int a[N], s[N];
int f[N][N];

void work()
{
	for(int i = 1; i <= n; ++ i) f[i][i] = a[i];
	for(int k = 2; k <= n; ++ k)
		for(int i = 1, j; i + k - 1 <= n; ++ i)
		{
			j = i + k - 1;

			f[i][j] = max (
				s[j] - s[i] - f[i+1][j] + a[i],
				s[j-1] - s[i-1] - f[i][j-1] + a[j]
			);
		}

	cout << f[1][n] << " " << s[n] - f[1][n] << endl;
}


int main()
{

	cin >> n;

	for(int i = 1; i <= n; ++ i)
		cin >> a[i],
		s[i] = s[i-1] + a[i];

	work();

	return 0;
}
