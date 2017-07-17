/*
	problem : Luogu 1310
	solution : DP
	
	评测结果：Accepted 
	得分：　　100
	提交时间：2017-06-30 22:54
	耗时：23ms
	内存：15167kb
*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 6;
const int MOD = 10007;

int n, m;
string str;

int opt[N];

int f[N][2], top;
int stk[N], stop;

void pop()
{
	int c = stk[stop];  --stop;
	if(c == -1) return;

	int x0 = f[top][0], x1 = f[top][1]; --top;
	int y0 = f[top][0], y1 = f[top][1];
	
	if(c == 1)
	{
		f[top][0] = x0 * y0 % MOD;
		f[top][1] = ((x0 * y1 + x1 * y0) % MOD + x1 * y1) % MOD;
	}
	else
	{
		f[top][0] = ((x0 * y1 + x1 * y0) % MOD + x0 * y0) % MOD;
		f[top][1] = x1 * y1 % MOD;
	}
}

int work()
{
	for(int i = 1; i <= n; ++ i)
	{
		if(opt[i] == -1) stk[ ++stop ] = -1;
		else if(opt[i] == -2)
		{
			for(; stk[stop] != -1; pop());
			pop();
		}
		else if(opt[i])
		{
			for(; stk[stop] >= opt[i]; pop());
			stk[ ++stop ] = opt[i];
		}
		else ++top, f[top][0] = f[top][1] = 1;
	}
	
	return f[1][0];
}

int main()
{
	freopen("T27.in", "r", stdin);

	cin >> m;
	cin >> str;
	str = '(' + str + ')', m += 2;

	opt[n=1] = -1;
	
	for(int i = 1; i < m; ++ i)
	{
		if(str[i] != '(' && str[i-1] != ')') ++n;

		if(str[i] == '+') opt[++n] = 1;
		else if(str[i] == '*') opt[++n] = 2;
		else if(str[i] == '(') opt[++n] = -1;
		else opt[++n] = -2;
	}
	if(str[m-1] != ')') ++n;

	cout << work() << endl;

	return 0;
}
