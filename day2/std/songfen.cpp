#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

long long ans;

int T, n, p, a[1100];

void doit() {
    long long p = 0, s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        ans = max(ans, s - p);
        p = min(p, s);
    }
}

int main() {
    freopen("songfen.in","r",stdin);
    freopen("songfen.out","w",stdout);
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ans = -1e18;
        for (int i = 1; i <= n; i++) {
            int t = a[i];
            a[i] = p;
            doit();
            a[i] = t;
        }
        printf("%I64d\n", ans);
    return 0;
}
