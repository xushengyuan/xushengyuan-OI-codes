//  邻接链表
const int  maxn = 100;
const int maxm = 100;
Struct e_t {
    int r, v, next;
}e[maxm];
int head[maxn];
int n, m, x, y, v;
void addEdge(int x, int y, int v) {
    e[line].r = y;
    e[line].v = v;
    e[line].next = head[x];
    head[x] = line++;
}
int main() {
    cin >> n >> m;
    memset(head, 0xff, sizeof(head));
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> v;
        addEdge(x, y, v);  // 有向图
    }
    return 0;
}

