#include <bits/stdc++.h>
#define task "minhbeo"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 16;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7][maxn + 7], dp[1 << maxn][maxn + 7];

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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            dp[mask][i] = inf;
        }
    }

    for (int i = 0; i < n; i++)
    {
        dp[1 << i][i] = 0;
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)) || dp[mask][i] == inf)
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (mask & (1 << j))
                {
                    continue;
                }
                int new_mask = mask | (1 << j);
                dp[new_mask][j] = std::min(dp[new_mask][j], dp[mask][i] + a[i][j]);
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        ans = std::min(ans, dp[(1 << n) - 1][i]);
    }

    std::cout << ans << "\n";
    return 0;
}
