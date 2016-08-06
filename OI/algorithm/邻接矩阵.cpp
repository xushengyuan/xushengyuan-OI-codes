//  ÁÚ½Ó¾ØÕó
const int maxn = 100;

int a[maxn][maxn];
int n, m, x, y, v;

int main()
{
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> v;
        a[x][y] = a[y][x] = v; //  ÎŞÏòÍ¼
    }
    return 0;
}

