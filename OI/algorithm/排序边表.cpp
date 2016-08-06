//排序边表（自己起的名字）
const int maxm = 100;

struct edge_t 
{
    int x, y, v;
}edge[maxm];

int n, m, x, y, v;

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> v;
        edge[i].x = x;
        edge[i].y = y;
        edge[i].v = v;
    }
    sort(edge, edge+m, cmp);
    return 0;
}

