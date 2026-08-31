#include <bits/stdc++.h>
#define task "whome"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int n, m, p, c;
int a[maxn + 7], s[10];
int dp[maxn + 7][1 << 6];

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

    std::cin >> n >> m >> p >> c;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> s[i];
    }

    std::sort(a, a + n);
    std::sort(s, s + m);

    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << m); mask++)
        {
            dp[i][mask] = -inf;
        }
        dp[i][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << m); mask++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i - s[j] + 1 >= 0)
                {
                    int new_mask = mask | (1 << j);
                    if (i - s[j] >= 0)
                    {
                        if (dp[i - s[j]][mask] == -inf)
                        {
                            dp[i][new_mask] = std::max(dp[i][new_mask], dp[i - s[j]][mask] + dp[i - s[j]][mask] + p - (a[i] - a[i - s[j] + 1]) * (a[i] - a[i - s[j] + 1]) * c);
                        }
                    }
                    else
                    {
                        if (mask == 0)
                        {
                            dp[i][new_mask] = std::max(dp[i][new_mask], p - (a[i] - a[i - s[j] + 1]) * (a[i] - a[i - s[j] + 1]) * c);
                        }
                    }
                }
            }
        }
    }

    int ans = -inf;
    for (int i = 0; i < n; i++)
    {
        ans = std::max(ans, dp[i][(1 << m) - 1]);
    }

    std::cout << ans << "\n";
    return 0;
}
