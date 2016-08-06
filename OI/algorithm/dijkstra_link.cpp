#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

const int maxn = 1000000+10;
const int maxm = 5500000+10;
const int inf  = (1<<30)-1;

struct e_t
{
	int r, v, next;
}e[maxm];

int n, seed;
int line, head[maxn];
int Prev[maxn], Next[maxn];
int dis[maxn];

unordered_map<int,int> list;

void addEdge(int l, int r, int v)
{
	e[line].r = r;
	e[line].v = v;
	e[line].next = head[l];
	head[l] = line++;
}

void BuildGraph()
{
	line = 0;
	memset(head, 0xFF, sizeof(head));

	cin >> n >> seed;

	unsigned long long next_rand = seed;
	for (int x = 1; x <= n; ++x)
	{
		int v = x % 10 + 1;
		int d = 10 - v;
		for (int i = 1; i <= d; ++i) 
		{
			addEdge(x, next_rand % n + 1, v);
			next_rand = next_rand * 233;
		}
		addEdge(x, x % n + 1, v);
	}
}

void push(int x)
{
	unordered_map<int,int>::iterator ptr;
	ptr = list.find(dis[x]);
	if (ptr == list.end())
		list[dis[x]] = x;
	else
	{
		int p = ptr->second;
		Prev[x] = Prev[p];
		Next[Prev[x]] = x;
		Next[x] = p;
		Prev[p] = x;
	}
}

void pop(int x)
{
	if (dis[x] == inf) return;
	if (Next[x] == x)
		list.erase(dis[x]);
	else
	{
		unordered_map<int,int>::iterator ptr;
		ptr = list.find(dis[x]);
		if (ptr->second == x)
			ptr->second = Next[x];
		Next[Prev[x]] = Next[x];
		Prev[Next[x]] = Prev[x];
	}
}

int top(int &current)
{
	unordered_map<int,int>::iterator ptr;
	while ((ptr = list.find(current)) == list.end())
		++current;
	int p = ptr->second;
	if (Next[p] == p)
		list.erase(ptr);
	else
	{
		ptr->second = Next[p];
		Next[Prev[p]] = Next[p];
		Prev[Next[p]] = Prev[p];
	}
	return p;
}

void Dijkstra()
{
	list.clear();
	for (int i = 1; i <= n; ++i)
	{
		dis[i] = inf;
		Prev[i] = Next[i] = i;
	}
	int current = 0;
	dis[1] = 0;
	push(1);
	for (int i = 2; i <= n; ++i)
	{
		int x = top(current);
		for (int j = head[x]; j != -1; j = e[j].next)
			if (dis[x] + e[j].v < dis[e[j].r])
			{
				pop(e[j].r);
				dis[e[j].r] = dis[x] + e[j].v;
				push(e[j].r);
			}
	}

	cout << dis[n] << endl;
}

int main(int argc, char **argv)
{
	freopen("data.in", "r", stdin);
	freopen("dijkstra.out", "w", stdout);

	int start = clock();

	int test;

	cin >> test;
	while (test--)
	{
		BuildGraph();
		Dijkstra();
	}

	cerr << clock() - start << endl;

	return 0;
}