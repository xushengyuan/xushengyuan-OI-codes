#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 2;
const int oo = (1<<30)-1;

bool vis[maxn];
int n, a[maxn][maxn], dis[maxn];

int s2i(string x)
{
	int y;
	stringstream f;
	f << x; f >> y;
	return y;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		a[i][i] = 0;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
		{
			string tmp;
			cin >> tmp;
			if (tmp == "x")
				a[i][j] = a[j][i] = oo;
			else
				a[i][j] = a[j][i] = s2i(tmp);
		}

	for (int i = 1; i <= n; ++i)
	{
		dis[i] = oo; vis[i] = false;
	}
	dis[1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x = 0;
		for (int j = 1; j <= n; ++j)
			if (vis[j] == false && (x == 0 || dis[j] < dis[x])) x = j;
		vis[x] = true;
		for (int j = 1; j <= n; ++j)
			if (dis[x] + a[x][j] < dis[j])
				dis[j] = dis[x] + a[x][j];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dis[i]);
	cout << ans << endl;

	return 0;
}