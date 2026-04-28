#include <bits/stdc++.h>
#define task "CaiTui"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100;
const int maxx = 1e5;
const int inf  = 1e18;

int n, s;
int dp[maxn + 7][maxx + 7];
ii a[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    for (int j = 1; j <= s; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (j >= a[i].fi)
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - a[i].fi] + a[i].se);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::cout << dp[n][s];

    return 0;
}