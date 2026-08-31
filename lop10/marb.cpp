#include <bits/stdc++.h>
#define task "marb"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 200;
const int inf  = 1e18;

int n, m, k;
int dp[maxn + 7][maxn + 7][maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> k;

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= k; ++i)
    {
        dp[0][0][i] = 1;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int l = 0; l <= k; ++l)
            {
                int s = 0;
                int mn = std::min(l, j / i);
                for (int t = 0; t <= mn; t++)
                {
                    s += dp[i - 1][j - t * i][l - t];
                }
                dp[i][j][l] = s;
            }
        }
    }

    std::cout << dp[m][n][k];

    return 0;
}
