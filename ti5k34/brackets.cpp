#include <bits/stdc++.h>
#define task "brackets"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 123456789;

int n, k;
int dp[maxn + 7][maxn + 7];

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

    std::cin >> n >> k;

    if (n % 2 != 0)
    {
        std::cout << 0;
        return 0;
    }

    n /= 2;

    for (int i = 0; i <= k; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int t = 0; t < i; t++)
            {
                dp[i][j] += dp[t][j - 1] * dp[i - 1 - t][j];
                dp[i][j] %= mod;
            }
        }
    }

    std::cout << ((dp[n][k] - dp[n][k - 1] + mod) % mod);

    return 0;
}
