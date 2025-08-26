#include <bits/stdc++.h>
#define task "tkseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, k;
int a[maxn + 7], dp[maxn + 7][maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i > 3 * k)
        {
            dp[i][i] = std::max(dp[i - 1][i - 1], dp[i - 1][i]);
        }
        else
        {
            int tmp = a[i];
            if (i % 3 == 2)
            {
                tmp = -a[i];
            }
            dp[i][i] = dp[i - 1][i - 1] + tmp;
        }

        for (int j = i + 1; j <= n; j++)
        {
            int tmp = a[j];
            if (i % 3 == 2)
            {
                tmp = -a[j];
            }
            dp[i][j] = std::max(dp[i - 1][j - 1] + tmp, dp[i][j - 1]);
        }
    }

    std::cout << dp[3 * k][n];

    return 0;
}
