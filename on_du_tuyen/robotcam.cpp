#include <bits/stdc++.h>
#define task "robotcam"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
iii a[maxn + 7];
int dp[maxn + 7], ans, f[maxn + 7];

bool cmp(iii a, iii b)
{
    if (a.fi.fi == b.fi.fi)
    {
        return a.fi.se < b.fi.se;
    }
    return a.fi.fi < b.fi.fi;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }

    std::sort(a + 1, a + n + 1, cmp);

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i].fi.fi << " " << a[i].fi.se << "\n";
    }*/

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = std::upper_bound(f + 1, f + ans + 1, a[i].fi.se) - f;
        if (dp[i] > ans)
        {
            ans++;
        }
        f[dp[i]] = a[i].fi.se;
    }

    std::cout << ans << "\n";

    int tmp = inf;
    std::vector<int> v;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] == ans && a[i].fi.se <= tmp)
        {
            tmp = a[i].fi.se;
            ans--;
            v.pb(a[i].se);
        }
    }

    std::reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    return 0;
}
