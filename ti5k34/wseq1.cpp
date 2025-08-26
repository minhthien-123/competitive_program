#include <bits/stdc++.h>
#define task "wseq1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e3;
const int inf = 1e18;

int n, m, k;
int a[maxn + 7];
int dp[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];
int ans = inf;

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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int p = 0; p < k; p++)
            {
                f[j][p] = inf;
            }
        }

        for (int j = 0; j <= m; j++)
        {
            for (int p = 0; p < k; p++)
            {
                if (dp[j][p] == inf)
                {
                    continue;
                }

                if (j < m)
                {
                    f[j + 1][p] = std::min(f[j + 1][p], dp[j][p]);
                }

                int t = (p + 1) % k, tmp = 0;
                if (t != 0)
                {
                    tmp = a[i];
                }
                f[j][t] = std::min(f[j][t], dp[j][p] + tmp);
            }
        }

        for (int j = 0; j <= m; j++)
        {
            for (int p = 0; p < k; p++)
            {
                dp[j][p] = f[j][p];
            }
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ans = std::min(ans, dp[i][j]);
        }
    }

    std::cout << ans;

    return 0;
}
