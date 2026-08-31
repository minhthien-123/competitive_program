#include <bits/stdc++.h>
#define task "vsteps"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 14062008;
const int inv  = (mod + 1) / 2;

int n, k;
bool a[maxn + 7];
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

    std::cin >> n >> k;
    for (int i = 1, x; i <= k; i++)
    {
        std::cin >> x;
        a[x] = 1;
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!a[i])
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
    }

    std::cout << dp[n];

    return 0;
}
