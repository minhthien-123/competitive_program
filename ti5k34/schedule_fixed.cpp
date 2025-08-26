#include <bits/stdc++.h>
#define task "schedule"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, s = 0, ans = 0;
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].se;
    }

    std::sort(a + 1, a + n + 1, [](ii a, ii b){
        return a.fi * b.se > b.fi * a.se;
    });

    for (int i = 1; i <= n; i++)
    {
        s += a[i].fi;
    }

    for (int i = 1; i <= n; i++)
    {
        ans += s * a[i].se;
        s -= a[i].fi;
    }

    std::cout << ans;

    return 0;
}
