/*
	problem : Luogu 2733
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 19:06
	耗时：22ms
	内存：12132kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 255;

int n;
string a[N];

int f[N][N];
int t[N];

void work()
{
	for(int i = 0; i < n; ++ i) f[i][0] = a[i][0] == '1';
	for(int j = 0; j < n; ++ j) f[0][j] = a[0][j] == '1';

	for(int i = 1; i < n; ++ i)
		for(int j = 1; j < n; ++ j) if(a[i][j] == '1')
		{
			f[i][j] = min( min(f[i-1][j], f[i][j-1]), f[i-1][j-1] ) + 1;
			t[ f[i][j] ] ++;
		}

	for(int i = n; i; i --)
		t[i-1] += t[i];

	for(int i = 2; i <= n; ++ i) if(t[i])
		cout << i << " " << t[i] << endl;
}


int main()
{

	cin >> n;

	for(int i = 0; i < n; ++ i)
		cin >> a[i];

	work();

	return 0;
}
