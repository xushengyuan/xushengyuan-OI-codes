//Date:2018/8/7
//OJ:luogu
//Problem:1991
//Solution:Kru
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 250010
using namespace std;
int u[MAXN], v[MAXN], point[MAXN], mi[MAXN];
float weight[MAXN];
int m, s, p;
/*int getint()
{
    int 
}*/
bool cmp(int a, int b)
{
    return weight[a] < weight[b];
}
int find(int x)
{
    return point[x] == x ? x : point[x] = find(point[x]);
}
void pre()
{
    int i;
    for (i = 0; i < p; i++)
        point[i] = i;
    for (i = 0; i < m; i++)
        mi[i] = i;
    sort(mi, mi + m, cmp);
    return;
}
int x[MAXN], y[MAXN];
void get()
{
    cin >> s >> p;
    m = 0;
    for (int i = 0; i < p; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p; j++)
        {
            u[m] = i, v[m] = j, weight[m] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            m++;
        }
    return;
}
vector<float> kruskal()
{
    int i, sum = 0, e;
    int e_x, e_y;
    vector<float> arr;
    for (i = 0; i < m; i++)
    {
        e = mi[i];
        e_x = find(u[e]), e_y = find(v[e]);
        if (e_x != e_y)
        {
            point[e_x] = e_y;
            arr.push_back(weight[e]);
        }
    }
    return arr;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i;
    get();
    pre();
    vector<float> ans;
    ans = kruskal();
    //for(int i=0;i<ans.size();i++)
    //    cout<<ans[i]<<endl;
    printf("%.2lf", ans[ans.size() - s ]);
    return 0;
}