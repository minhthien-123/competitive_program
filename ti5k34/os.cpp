#include <bits/stdc++.h>
#define task "os"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 1e5 + 7;

bool cmp(ii a, ii b)
{
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

ii a[maxn];
int n, m, ans = 0;
int lastEnd = -1;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        if (a[i].fi > lastEnd)
        {
            ans++;
            lastEnd = a[i].se;
        }
    }

    std::cout << ans;

    return 0;
}
