//æ≠µ‰BFS
int BFS(int s, int t)
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    int take = 0, put = 1, x;
    que[put] = s;
    vis[s] = true;
    dis[s] = 0;
    while (take != put)
    {
        x = que[++take];
        for (int I = head[x]; I != -1; I = e[i].next)
             if (!vis[e[i].r])
            {
                que[++put] = e[i].r;
                dis[e[i].r] = dis[x] + 1;
                vis[e[i].r] = true;
            }
    }
    return dis[t];
}

