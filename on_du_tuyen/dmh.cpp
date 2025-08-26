#include <bits/stdc++.h>
#define task "pa"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int32_t main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

#ifdef LOCAL
    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }
#endif

    int n;
    std::cin >> n;
    std::vector<int> d(n);
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> d[i];
        S += d[i];
    }

    // dp[i][y] = max horizontal sum x after i moves with vertical sum = y
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(S + 1, -inf));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y <= S; y++)
        {
            if (dp[i][y] < 0)
                continue;
            // move up: y -> y + d[i], x stays
            if (y + d[i] <= S)
                dp[i + 1][y + d[i]] = std::max(dp[i + 1][y + d[i]], dp[i][y]);
            // move right: y stays, x += d[i]
            dp[i + 1][y] = std::max(dp[i + 1][y], dp[i][y] + d[i]);
        }
    }

    long long ans = 0;
    // sum all reachable x for final row i = n
    for (int y = 0; y <= S; y++)
    {
        if (dp[n][y] >= 0)
        {
            ans += (dp[n][y] + 1);
        }
    }
    // add vertical cells
    ans += S;

    std::cout << ans << '\n';
    return 0;
}
