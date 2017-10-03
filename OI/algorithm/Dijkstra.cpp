void Dijkstra(int s, int t)
{
    for (int i = 0; i < maxn; ++i)
        dis[i] = INF, vis[i] = false;
    dis[s] = 0;
    for (int i = 0; i < n; ++i)
    {
        int p = 0;  // 默认顶点编号1~n
        for (int j = 1; j <= n; ++j)  // 可优化
            if (vis[j] && dis[j] < dis[p]) p = j;
        if (p == 0) break;
        vis[p] = true;
        for (int j = head[p]; j != -1; j = e[j].next)
            if (dis[e[j].r] > dis[p] + e[j].v)
                dis[e[j].r] = dis[p] + e[j].v;
    }
}

