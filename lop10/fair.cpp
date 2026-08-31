#include <bits/stdc++.h>
#define task "fair"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5000;
const int inf  = 1e18;
const int mod  = 123456789;

int n, m, d = 0;
int ans;
int a[maxn + 7], f[maxn + 7], dp[maxn + 7][maxn + 7];

void Try1(int i, int s)
{
    if (i > n / 2)
    {
        f[d++] = s;
        return;
    }

    Try1(i + 1, s);
    if (s + a[i] <= m)
    {
        Try1(i + 1, s + a[i]);
    }
}

void Try2(int i, int s)
{
    if (i > n)
    {
        ans += std::upper_bound(f, f + d, m - s) - std::lower_bound(f, f + d, m - s);
        return;
    }

    Try2(i + 1, s);
    if (s + a[i] <= m)
    {
        Try2(i + 1, s + a[i]);
    }
}

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
        std::cin >> a[i];
    }
    if (n <= 40)
    {
        Try1(1, 0);
        std::sort(f, f + d);
        Try2(n / 2 + 1, 0);
        std::cout << ans % mod << "\n";
        return 0;
    }

    dp[1][0] = 1;
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j] % mod;
            if (j >= a[i])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
            }
        }
    }
    std::cout << dp[n][m] << "\n";

    return 0;
}
