/*
	Problem : POJ 1384
	Solution : DP
	Result : MLE
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 505;
const int M = 10005;
const int INF = 1e9;

int T, n, m;
int f[N][M];
int p[N], w[N];

void work()
{
	int a1, a2;
	cin >> a1 >> a2 >> n;
	
	m = a2 - a1;
	for(int i = 1; i <= n; ++ i) cin >> p[i] >> w[i];

	for(int i = 1; i <= n + 1; ++ i)
		for(int j = 0; j <= m; ++ j) f[i][j] = INF;

	f[1][0] = 0;
	
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= m; ++ j) if(f[i][j] < INF)
			for(int k = 0; j + w[i] * k <= m; ++ k)
				f[ i+1 ][ j+w[i]*k ] = min( f[ i+1 ][ j+w[i]*k ], f[i][j] + p[i]*k );

	if(f[n+1][m] == INF) cout << "This is impossible." << endl;
	else cout << "The minimum amount of money in the piggy-bank is " << f[n+1][m] << "." << endl;
}

int main()
{
	cin >> T;
	for(int i = 0; i < T; ++ i) work();
	return 0;
}
