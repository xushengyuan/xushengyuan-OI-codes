#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int getint()
{
	char ch;
	int x = 0;
	do ch = getchar();
	while (!('0' <= ch && ch <= '9'));
	do
	{
		x = x*10 + (int)(ch-'0');
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	return x;
}

struct edge_t
{
	int x, y, v;
};

struct edge_t *edge;

int n, m, *belong;

void ParseArgv(int argc, char **argv)
{
	if (argc < 3)
	{
		cerr << "Error with argv" << endl;
		cerr << argv[0] << " input_file output_file [error_file]" << endl;
		exit(1);
	}
	freopen(argv[1], "r", stdin);
	freopen(argv[2], "w", stdout);
	if (argc > 3)
		freopen(argv[3], "w", stderr);
}

bool cmpE(edge_t a, edge_t b)
{
	return a.v < b.v;
}

void Init()
{
	n = getint();
	m = getint();
	edge = new edge_t[m];
	for (int i = 0; i < m; ++i)
	{
		edge[i].x = getint();
		edge[i].y = getint();
		edge[i].v = getint();
	}
	sort(edge, edge+m, cmpE);
}

int getBelong(int x)
{
	if (belong[x] < 0) return x;
	return belong[x] = getBelong(belong[x]);
}

void Kruskal()
{
	int x, y, fx, fy;

	belong = new int[n];
	for (int i = 0; i < n; ++i)
		belong[i] = -1;
	int edgeNum = 0;
	long long cost = 0;
	for (int i = 0; i < m; ++i)
	{
		x = edge[i].x;
		y = edge[i].y;
		fx = getBelong(x);
		fy = getBelong(y);
		if (fx == fy) continue;
		if (belong[fx] > belong[fy]) swap(fx, fy);
		belong[fx] += belong[fy];
		belong[fy] = fx;
		cost += edge[i].v;
		if (++edgeNum == n-1) break;
	}
	if (edgeNum < n-1)
		cout << "Disconnect" << endl;
	else
		cout << cost << endl;
}

int main(int argc, char **argv)
{
	clock_t start = clock();

	ParseArgv(argc, argv);
	Init();
	Kruskal();
	
	cerr << clock() - start << endl;

	return 0;
}