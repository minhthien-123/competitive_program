#include <bits/stdc++.h>
#define task "ball"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int t;
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

    dp[1] = 2;
    for (int i = 1; i <= maxn; i++)
    {
        dp[i + 1] = dp[i] * 4 * (2 * i + 1);
        dp[i + 1] %= mod;
    }

    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << dp[n] % mod << "\n";
    }

    return 0;
}
