#include <bits/stdc++.h>
#define task "hoicho"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5 + 7;
const int inf  = 1e18;

int x[maxn], c[maxn], dp[maxn];
int n, m;

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x[i];
        dp[i] = inf;
    }

    std::sort(x + 1, x + n + 1);

    for (int i = 1; i <= m; i++)
    {
        std::cin >> c[i];
    }
    c[m + 1] = inf;

    for (int i = m; i >= 1; i--)
    {
        c[i] = std::min(c[i], c[i + 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = std::min(dp[j], dp[i - 1] + c[x[j] - x[i] + 1]);
        }
    }
    /*for (int i = 1; i <= n; i++)
    {
        std::cout << dp[i] << " ";
    }*/
    std::cout << dp[n];

    return 0;
}
