#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int n;
ii a[maxn];
std::vector<ii> res;

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
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i].se >> a[i].fi;
    }

    std::sort(a + 1, a + n + 1);

    res.pb({a[1].fi, a[1].se});
    int end = a[1].fi;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].se > end)
        {
            end = a[i].fi;
            res.pb({a[i].fi, a[i].se});
        }
    }

    std::cout << res.size() << "\n";
    for (auto i : res)
    {
        std::cout << i.se << " " << i.fi << "\n";
    }

    return 0;
}
