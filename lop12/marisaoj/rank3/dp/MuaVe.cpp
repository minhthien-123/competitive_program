#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n;
int t[maxn], r[maxn];
int dp[maxn];

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

    for (int i = 2; i <= n; i++)
    {
        std::cin >> r[i];
    }

    dp[1] = t[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = std::min(dp[i - 1] + t[i], dp[i - 2] + r[i]);
    }

    std::cout << dp[n];

    return 0;
}
