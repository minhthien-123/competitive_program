#include <bits/stdc++.h>
#define task "wseq2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;

int n, m, k;
int x[maxn + 7], y[maxn + 7];
int dp[maxn + 7][maxn + 7];
int s = 0, t;

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
    t = std::min(m + n, k);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x[i];
        s += x[i];
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> y[i];
        s += y[i];
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -inf;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            if (i > 0)
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + x[i]);
            }

            if (j > 0)
            {
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1] + y[j]);
            }
        }
    }

    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        int j = t - i;
        //std::cout << i << " " << j << std::endl;
        if (j >= 0 && j <= n)
        {
            ans = std::max(ans, dp[i][j]);
        }
    }

    //std::cout << ans;

    std::cout << s - ans;

    return 0;
}
