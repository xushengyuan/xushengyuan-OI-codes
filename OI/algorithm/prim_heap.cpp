#include <queue>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int INF = (1<<30)-1;

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

struct e_t
{
	int to, val, next;
};

struct e_t *e;

int n, m, line, *head;

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

void addEdge(int x, int y, int v)
{
	e[line].to = y;
	e[line].val = v;
	e[line].next = head[x];
	head[x] = line++;
}

void Init()
{
	int x, y, v;

	n = getint();
	m = getint();
	line = 0;
	head = new int[n];
	for (int i = 0; i < n; ++i)
		head[i] = -1;
	e = new e_t[m<<1];
	for (int i = 0; i < m; ++i)
	{
		x = getint();
		y = getint();
		v = getint();
		addEdge(x, y, v);
		addEdge(y, x, v);
	}
}

void Prim_Heap()
{
	int *dis = new int[n];
	bool *used = new bool[n];
	for (int i = 0; i < n; ++i)
		dis[i] = INF, used[i] = false;
	dis[0] = 0;
	priority_queue <pair<int,int> > Q;
	Q.push(make_pair(-dis[0], 0));

	long long cost = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		for (x = -1; !Q.empty() && (x == -1 || used[x]);)
		{
			x = Q.top().second;
			Q.pop();
		}
		if (x == -1 || used[x]) {cost = -1; break;}
		cost += dis[x];
		used[x] = true;
		for (int j = head[x]; j != -1; j = e[j].next)
			if (e[j].val < dis[e[j].to])
			{
				dis[e[j].to] = e[j].val;
				Q.push(make_pair(-dis[e[j].to], e[j].to));
			}
	}
	if (cost == -1)
		cout << "Disconnect" << endl;
	else
		cout << cost << endl;
}

int main(int argc, char **argv)
{
	clock_t start = clock();

	ParseArgv(argc, argv);
	Init();
	Prim_Heap();
	
	cerr << clock() - start << endl;

	return 0;
}