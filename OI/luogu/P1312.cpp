//Date:2018/7/20
//OJ:luogu
//Problem:1312
//Solution:DFS
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int n;
int data[10][10][10];
struct mov
{
    int x, y, g;
};
stack<mov> S;

void fall(int p)
{
    vector<int> tmp;
    for (int i = 0; i < 5; i++)
    {
        tmp.clear();
        for (int j = 6; j >= 0; j--)
            if (data[p][i][j] != 0)
                tmp.push_back(data[p][i][j]);
        for (int j = 0; j < 7; j++)
            data[p][i][j] = 0;
        //std::cout << tmp.size() << '\n';
        int len=tmp.size();
        for (int j = 6; j >= 7 - len; j--)
            data[p][i][j] = tmp[6 - j];
    }
    return;
}
void check(int p)
{
    bool del[10][10];
    /*for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            tmp[i][j][0] = tmp[i][j][1] = 1;*/
    memset(del, 0, sizeof(del));
    /*for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
        {
            if (i != 0 && data[p][i - 1][j] == data[p][i !][j])
                tmp[i][j][0] = data[i - 1][j][0] + 1;
            if (j != 0 && data[p][i][j - 1] == data[p][i][j])
                tmp[i][j][1] = data[i][j - 1][1] + 1;
        }*/
    int t = 1;
    for (int i = 0; i <= 5; i++)
    {
        t = 1;
        for (int j = 0; j <= 7; j++)
        {
            //if (data[p][i][j] == 0)
            //    continue;
            if (data[p][i][j] != 0 && j != 0 && data[p][i][j - 1] == data[p][i][j])
                t++;
            else if (t >= 3)
            {
                for (int k = j - t; k < j; k++)
                    del[i][k] = true;
                t = 1;
            }
            else
                t=1;
            //cout<<t<<' ';
        }
        //cout<<endl;
    }
    for (int j = 0; j <= 7; j++)
    {
        t = 1;
        for (int i = 0; i <= 5; i++)
        {
            //if (data[p][i][j] == 0)
            //    continue;
            if (data[p][i][j] != 0 && i != 0 && data[p][i - 1][j] == data[p][i][j])
                t++;
            else if (t >= 3)
            {
                for (int k = i - t; k < i; k++)
                    del[k][j] = true;
                t = 1;
            }
            else
                t=1;
            //cout<<t<<' ';
        }
        //cout<<endl;
    }
    bool flag = false;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            if (del[i][j])
                data[p][i][j] = 0, flag = true;
    fall(p);
    /*cout<<"-----------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
            cout << data[p][i][j] << ' ';
        cout << endl;
    }
    cout<<"-----------"<<endl;*/
    if (flag)
        check(p);
    flag = false;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            if (data[p][i][j] != 0)
                flag = true;
    if (!flag && p==n)
    {
        stack<mov> tmp;
        while (!S.empty())
        {
            tmp.push(S.top());
            S.pop();
        }
        while (!tmp.empty())
        {
            cout << tmp.top().x << ' ' << 6 - tmp.top().y << ' ' << tmp.top().g << endl;
            tmp.pop();
        }
        exit(0);
    }
    return;
}
void dfs(int k)
{
    int p = n - k + 2;
    bool flag = false;
    if (k == 1)
        return;
    memcpy(data[p],data[p-1],10*10*sizeof(int));
    /*cout << p << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
            cout << data[p][i][j] << ' ';
        cout << endl;
    }*/
    for (int i = 0; i < 5; i++)
    {
        for (int j = 6; j >=0 ; j--)
        {
            if (data[p][i][j] == 0)
                continue;
            flag = true;
            if (i != 4)
            {
                if (data[p][i][j] != data[p][i + 1][j])
                {
                    memcpy(data[p],data[p-1],10*10*sizeof(int));
                    int t = data[p][i + 1][j];
                    data[p][i + 1][j] = data[p][i][j];
                    data[p][i][j] = t;
                    fall(p);
                    S.push({i, j, 1});
                    check(p);
                    //cout << i << ' ' << 6 - j << ' ' << 1 << endl;
                    dfs(k - 1);
                    memcpy(data[p],data[p-1],10*10*sizeof(int));
                    S.pop();
                }
            }
            if (i != 0)
            {
                if (data[p][i - 1][j] == 0)
                {
                    memcpy(data[p],data[p-1],10*10*sizeof(int));
                    data[p][i - 1][j] = data[p][i][j];
                    data[p][i][j] = 0;
                    fall(p);
                    S.push({i, j, -1});
                    check(p);
                    //cout << i << ' ' << 6 - j << ' ' << -1 << endl;
                    dfs(k - 1);
                    memcpy(data[p],data[p-1],10*10*sizeof(int));
                    S.pop();
                }
            }
        }
    }
    if (!flag)
    {
        stack<mov> tmp;
        while (!S.empty())
        {
            tmp.push(S.top());
            S.pop();
        }
        while (!tmp.empty())
        {
            cout << tmp.top().x << ' ' << tmp.top().y << ' ' << tmp.top().g << endl;
            tmp.pop();
        }
        exit(0);
    }
    //cout << endl;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    int t = -1, p = 0;
    memset(data, 0, sizeof(data));
    for (int i = 0; i < 5; i++)
    {
        p = 6;
        cin >> t;
        while (t != 0)
        {
            data[0][i][p--] = t;
            cin >> t;
        }
    }
    /*for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
            cout << data[0][i][j] << ' ';
        cout << endl;
    }*/
    dfs(n + 1);
    /*cout << endl;
    check(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
            cout << data[0][i][j] << ' ';
        cout << endl;
    }*/
    cout << -1;
    return 0;
}
