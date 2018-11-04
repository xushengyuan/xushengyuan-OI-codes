//Date:2018/20/24
//OJ:
//Problem:
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
#define MAXN 1100
using namespace std;
int a, b, n;
int data[MAXN][MAXN], data2[2][MAXN][MAXN];
int read_int()
{
    int result = 0;
    char t = getchar();
    while (!isdigit(t))
        t = getchar();
    while (isdigit(t))
    {
        result = result * 10 + t - '0';
        t = getchar();
    }
    return result;
}
int st1[2][MAXN][MAXN][10];
void build_st1(int index)
{
    for (int i = 0; i < b + 1; i++)
    {
        st1[0][index][i][0] = data[index][i];
        st1[1][index][i][0] = data[index][i];
    }
    for (int j = 1; (1 << j) <= b + 1; j++)
        for (int i = 0; i + (1 << j) - 1 < b + 1; i++)
        {
            st1[0][index][i][j] = min(st1[0][index][i][j - 1], st1[0][index][i + (1 << (j - 1))][j - 1]);
            st1[1][index][i][j] = max(st1[1][index][i][j - 1], st1[1][index][i + (1 << (j - 1))][j - 1]);
        }
    return;
}
void build_st2(int index)
{
    for (int i = 0; i < a + 1; i++)
    {
        st1[0][index][i][0] = data2[0][i][index];
        st1[1][index][i][0] = data2[1][i][index];
    }
    for (int j = 1; (1 << j) <= a + 1; j++)
        for (int i = 0; i + (1 << j) - 1 < a + 1; i++)
        {
            st1[0][index][i][j] = min(st1[0][index][i][j - 1], st1[0][index][i + (1 << (j - 1))][j - 1]);
            st1[1][index][i][j] = max(st1[1][index][i][j - 1], st1[1][index][i + (1 << (j - 1))][j - 1]);
        }
    return;
}
int query_st1(int sgn, int index, int L, int R)
{
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1)
        k++;
    if (sgn == 0)
        return min(st1[sgn][index][L][k], st1[sgn][index][R - (1 << k) + 1][k]);
    else
        return max(st1[sgn][index][L][k], st1[sgn][index][R - (1 << k) + 1][k]);
}
int query_st2(int sgn, int index, int L, int R)
{
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1)
        k++;
    if (sgn == 0)
        return min(st1[sgn][index][L][k], st1[sgn][index][R - (1 << k) + 1][k]);
    else
        return max(st1[sgn][index][L][k], st1[sgn][index][R - (1 << k) + 1][k]);
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> a >> b >> n;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            data[i][j] = read_int();
    for (int i = 0; i < a; i++)
        build_st1(i);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b - n + 1; j++)
        {
            data2[0][i][j] = query_st1(0, i, j, j + n - 1);
            data2[1][i][j] = query_st1(1, i, j, j + n - 1);
            // cout << data2[0][i][j] << '/' << data2[1][i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;
    memset(st1, 0, sizeof(st1));
    for (int i = 0; i < b - n + 1; i++)
        build_st2(i);
    int Min = 0x3fffffff;
    for (int i = 0; i < a - n + 1; i++)
    {
        for (int j = 0; j < b - n + 1; j++)
        {
            Min = min(Min, query_st2(1, j, i, i + n - 1) - query_st2(0, j, i, i + n - 1));
            // cout << query_st2(0, j, i, i + n - 1) << '/' << query_st2(1, j, i, i + n - 1) << " ";
        }
        // cout << endl;
    }
    cout << Min << endl;
    return 0;
}