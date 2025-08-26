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
std::vector<ii> ta, tb, t;

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

    for (int i = 1; i <= n; i++)
    {
        if (a[i].fi <= a[i].se)
        {
            ta.pb({a[i].fi, a[i].se});
        }
        else
        {
            tb.pb({a[i].se, a[i].fi});
        }
    }

    std::sort(ta.begin(), ta.end());
    std::sort(tb.begin(), tb.end(), std::greater<ii>());

    for (auto i : ta)
    {
        std::cout << i.fi << ' ' << i.se << "\n";
        t.pb(i);
    }
    for (auto i : tb)
    {
        std::cout << i.fi << ' ' << i.se << "\n";
        t.pb({i.se, i.fi});
    }

    int up = 0, down = 0;
    for (auto i : t)
    {
        int up1 = up;
        int up2 = up1 + i.fi;
        int down1 = std::max(up2, down);
        int down2 = down1 + i.se;

        up = up2;
        down = down2;
    }

    std::cout << down;

    return 0;
}
