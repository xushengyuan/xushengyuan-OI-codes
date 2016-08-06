#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 2;
const int oo = (1<<30)-1;

bool inq[maxn];
int n, a[maxn][maxn], dis[maxn], que[maxn];

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
		dis[i] = oo; inq[i] = false;
	}
	int take = 0, put = 1;
	dis[1] = 0;
	que[1] = 1;
	inq[1] = true;
	while (take != put)
	{
		if (++take >= maxn) take = 0;
		int x = que[take];
		for (int i = 1; i <= n; ++i)
			if (dis[x] + a[x][i] < dis[i])
			{
				dis[i] = dis[x] + a[x][i];
				if (!inq[i])
				{
					if (++put >= maxn) put = 0;
					que[put] = i;
					inq[i] = true;
				}
			}
		inq[x] = false;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dis[i]);
	cout << ans << endl;

	return 0;
}