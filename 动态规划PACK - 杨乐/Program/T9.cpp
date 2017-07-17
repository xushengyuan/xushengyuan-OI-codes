/*
	Problem : POJ 1384
	Solution : DP

	Run ID	Problem	Result	Memory	Time	Language	Code Length	Submit Time
	17114896	1384	Accepted	276K	157MS	C++	680B	2017-06-28 22:42:36
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 505;
const int M = 10005;
const int INF = 1e9;

int T, n, m;
int f[M];
int p[N], w[N];

int g[N][M];

void work1()
{
	int a1, a2;
	cin >> a1 >> a2 >> n;
	
	m = a2 - a1;
	for(int i = 1; i <= n; ++ i) cin >> p[i] >> w[i];

	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j) g[i][j] = INF;
	g[0][0] = 0;

	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j)
			for(int k = 0; j >= w[i] * k; ++ k)
				g[i][j] = min( g[i][j], g[i-1][j-w[i]*k] + p[i]*k );

	if(g[n][m] == INF) cout << "This is impossible." << endl;
	else cout << "The minimum amount of money in the piggy-bank is " << g[n][m] << "." << endl;
}

void work2()
{
	int a1, a2;
	cin >> a1 >> a2 >> n;
	
	m = a2 - a1;
	for(int i = 1; i <= n; ++ i) cin >> p[i] >> w[i];

	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j) g[i][j] = INF;
	g[0][0] = 0;

	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j)
		{
			g[i][j] = g[i-1][j];
			if(j >= w[i]) g[i][j] = min(g[i][j], g[i][j-w[i]] + p[i]);
		}

	if(g[n][m] == INF) cout << "This is impossible." << endl;
	else cout << "The minimum amount of money in the piggy-bank is " << g[n][m] << "." << endl;
}

void work3()
{
	int a1, a2;
	cin >> a1 >> a2 >> n;
	
	m = a2 - a1;
	for(int i = 1; i <= n; ++ i) cin >> p[i] >> w[i];

	for(int j = 0; j <= m; ++ j) f[j] = INF;

	f[0] = 0;
	
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j)
				if(j >= w[i]) f[j] = min( f[j], f[j-w[i]] + p[i] );

	if(f[m] == INF) cout << "This is impossible." << endl;
	else cout << "The minimum amount of money in the piggy-bank is " << f[m] << "." << endl;
}

int main()
{
	cin >> T;
	for(int i = 0; i < T; ++ i) work2();
	return 0;
}
