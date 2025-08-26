#include <bits/stdc++.h>
#define task "nktick"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int t[maxn + 7], r[maxn + 7];
int dp[maxn + 7][2];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> t[i];
    }
    for (int i = 1; i < n; i++)
    {
        std::cin >> r[i];
    }

    dp[1][0] = inf;
    dp[1][1] = t[1];
    dp[2][0] = r[1];
    dp[2][1] = t[1] + t[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1] - t[i - 1] + r[i - 1];
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + t[i];
    }

    std::cout << std::min(dp[n][0], dp[n][1]);

    return 0;
}
