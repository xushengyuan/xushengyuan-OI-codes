//Date:2018/9/6
//OJ:luogu
//Problem:1072
//Solution:Math
//By:xushengyuan
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
int T, a0, a1, b0, b1;
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> T;
    while (T--)
    {
        cin >> a0 >> a1 >> b0 >> b1;
        int ans = 0;
        for (int x = 1; x * x <= b1; x++)
            if (b1 % x == 0)
            {
                int xx = x, yy = b1 / xx;
                if (xx % a1 == 0 && gcd(xx / a1, a0 / a1) == 1 && gcd(b1 / b0, b1 / xx) == 1)
                    ans++;
                if (yy % a1 == 0 && xx != yy && gcd(yy / a1, a0 / a1) == 1 && gcd(b1 / b0, b1 / yy) == 1)
                    ans++;
            }
        cout << ans << endl;
    }
    return 0;
}