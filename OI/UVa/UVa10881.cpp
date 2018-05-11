//Date:2018/4/15    
//OJ:UVa
//Problem:10881
//Solution:Sort
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 10010
#define INF 0x7fffffff
#define ngINF -0x7fffffff
#define _DEBUG
using namespace std;
int Cases;
int l, t, n;
struct ant
{
    long long num, d, p;
};
ant data[MAXN], s[MAXN];
bool cmp_p(const ant a, const ant b)
{
    return a.p < b.p;
}
bool cmp_n(const ant a, const ant b)
{
    return a.num < b.num;
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> Cases;
    for(int Case=0;Case<Cases;Case++)
    {
        cin >> l >> t >> n;
        memset(data, 0, sizeof(data));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++)
        {
            int tmp;
            string str;
            cin >> tmp >> str;
            data[i].num = i;
            s[i].num = data[i].num;
            data[i].d = (str[0] == 'R' ? 1 : -1);
            s[i].d = data[i].d;
            data[i].p = tmp;
            s[i].p = tmp + data[i].d * t;
            if (s[i].p < 0)
                s[i].p=ngINF;
            else if(s[i].p>l)
                s[i].p=INF;
        }
        sort(data, data + n, cmp_p);
        sort(s, s + n, cmp_p);
        for (int i = 0; i < n; i++)
        {
            s[i].num=data[i].num;
            if(i<n-1 && s[i].p==s[i+1].p)
            {
                s[i].d=0;
                s[i+1].d=0;
            }
        }
        sort(s, s + n, cmp_n);
        cout<<"Case #"<<Case+1<<':'<<endl;
        for (int i = 0;i<n;i++)
            if(s[i].p==ngINF || s[i].p==INF)
                cout<<"Fell off"<<endl;
            else if(s[i].d==-1)
                cout<<s[i].p<<" L"<<endl;
            else if(s[i].d==0)
                cout<<s[i].p<<" Turning"<<endl;
            else
                cout<<s[i].p<<" R"<<endl;
        cout<<endl;
    }
    return 0;
}