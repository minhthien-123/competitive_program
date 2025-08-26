#include <bits/stdc++.h>
#define task "lcs2x14"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1500;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int t, n, m;
int tmp, cur;
int a[maxn + 7], b[maxn + 7];
int dp[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        std::cin >> m >> n;
        for (int i = 1; i <= m; i++)
        {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            std::cin >> b[i];
        }

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; i++)
        {
            cur = 0;
            for (int j = 1; j <= n; j++)
            {
                tmp = cur;
                if (2 * b[j] <= a[i])
                {
                    cur = std::max(cur, dp[j]);
                }
                if (a[i] == b[j])
                {
                    dp[j] = std::max(dp[j], tmp + 1);
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = std::max(res, dp[i]);
        }

        std::cout << res << "\n";
    }

    return 0;
}
