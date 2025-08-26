#include <bits/stdc++.h>
#define task "climbe"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n;
ii a[maxn + 7];


signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i].fi;
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i].se;
    }

    std::sort(a + 1, a + n + 1, std::greater<ii>());

    int ans = 0, cmp = 0;
    for (int i = 1; i <= n; i++)
    {
        //std::cout << a[i].fi << " " << a[i].se << "\n";
        cmp += a[i].fi;
        ans = std::max(ans, cmp + a[i].se);
    }

    std::cout << ans << '\n';

    return 0;
}
