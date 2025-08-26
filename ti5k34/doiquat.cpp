#include <bits/stdc++.h>
#define task "doiquat"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e3;
const int inf  = 1e18;

int n, m;
char a[maxn + 7][maxn + 7];
int dp[maxn + 7][maxn + 7];

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
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '0')
            {
                if (i == 1 || j == 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                ans += dp[i][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    std::cout << ans;

    return 0;
}
