#include <bits/stdc++.h>
#define task "fraction"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int dp[maxn + 7][2];
int n, w;
ii a[maxn + 7];
long double b[maxn + 7], f[maxn + 7];

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

    std::cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long double val = a[i].fi * 1.0 / a[i].se;
        int pos = std::lower_bound(f, f + ans, val) - f;
        f[pos] = val;
        if (pos == ans)
        {
            ans++;
        }
    }
    if (w == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                long double val;
                if (i == j)
                {
                    val = a[j].se * 1.0 / a[j].fi;
                }
                else
                {
                    val = a[j].fi * 1.0 / a[j].se;
                }
                int pos = std::lower_bound(f, f + cnt, val) - f;
                f[pos] = val;
                if (pos == cnt)
                {
                    cnt++;
                }
            }
            ans = std::max(ans, cnt);
        }
    }

    std::cout << ans << "\n";

    return 0;
}
