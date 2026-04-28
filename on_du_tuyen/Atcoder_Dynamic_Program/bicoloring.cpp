#include <bits/stdc++.h>
#define task "bicoloring"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod = 998244353;
const int inv  = (mod + 1) / 2;

int n, k;
int dp[maxn + 7][2 * maxn + 7][2];

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
    dp[1][1][0] = dp[1][2][1] = 2;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 2 * k; j++)
        {
            dp[i][j][0] = dp[i - 1][j][1] * 2 + dp[i - 1][j - 1][0] + dp[i - 1][j][0];
            dp[i][j][0] %= mod;
            dp[i][j][1] = dp[i - 1][j - 1][0] * 2 + dp[i - 1][j - 2][1] + dp[i - 1][j][1];
            dp[i][j][1] %= mod;
        }
    }

    std::cout << (dp[n][k][0] + dp[n][k][1]) % mod;

    return 0;
}
