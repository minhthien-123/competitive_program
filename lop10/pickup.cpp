#include <bits/stdc++.h>
#define task "pickup"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int INF = 1e18;

int n, m;
int t[maxn + 7];
int pre[maxn + 7];
int dp[maxn + 7][maxn + 7];

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
        std::cin >> t[i];
    }

    std::sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + t[i];
    }

    if (m >= n)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    return 0;
}
