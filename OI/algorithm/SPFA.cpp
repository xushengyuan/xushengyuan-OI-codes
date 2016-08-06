//SPFA
 while (take != put)
    {
        if (++take >= maxn) take = 0;
        x = que[take];
        for (int I = head[x]; I != -1; I = e[i].next)
             if (dis[x] + e[i].v < dis[e[i].r])
            {                
                dis[e[i].r] = dis[x] + e[i].v;
                if (!inq[e[i].r])
                {
                    if (++put >= maxn) put = 0;
                    que[put] = e[i].r;
                    inq[e[i].r] = true;
                }
            }
        inq[x] = false;
    }

