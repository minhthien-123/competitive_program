#include <bits/stdc++.h>
#define task "cover1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1);

    int ans = 0, l = a[1].fi, r = a[1].se;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].fi <= r)
        {
            r = std::max(r, a[i].se);
        }
        else
        {
            ans += r - l;
            l = a[i].fi;
            r = a[i].se;
        }
    }

    std::cout << ans + r - l;

    return 0;
}
