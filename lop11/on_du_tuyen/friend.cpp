#include <bits/stdc++.h>
#define task "friend"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
ii a[maxn + 7];
int ans;
long double g[maxn + 7];
std::pair<int, long double> f[maxn + 7];

bool cmp(ii a, ii b)
{
    if (a.fi == b.fi)
    {
        return a.se < b.se;
    }
    return a.fi > b.fi;
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

    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
        f[i] = {a[i].fi, a[i].fi + (long double)m / (long double)a[i].se};
    }

    std::sort(f + 1, f + n + 1, cmp);

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << f[i].fi << " " << f[i].se << "\n";
    }*/

    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = std::lower_bound(g + 1, g + ans + 1, f[i].se) - g;
        if (pos > ans)
        {
            ans++;
        }
        g[pos] = f[i].se;
    }

    std::cout << ans << "\n";

    return 0;
}
