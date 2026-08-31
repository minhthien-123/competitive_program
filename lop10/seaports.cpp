#include <bits/stdc++.h>
#define task "seaports"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n, m;
iii a[maxn + 7];

bool cmp (iii a, iii b)
{
    if (a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
    return a.fi.se < b.fi.se;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }

    std::sort(a + 1, a + m + 1, cmp);

    for (int i = 1; i <= m; i++)
    {
        //std::cout << a[i].fi.fi << " " << a[i].fi.se << "\n";
        std::cout << a[i].se << " ";
    }

    return 0;
}
