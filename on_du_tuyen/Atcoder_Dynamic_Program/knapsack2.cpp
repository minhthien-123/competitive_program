#include <bits/stdc++.h>
#define int long long

const int maxn = 1e6 + 7;
const int inf = 1e18 + 7;

int n, m;
int w[107], v[107], dp[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> w[i] >> v[i];
    for (int i = 2; i <= maxn; i++)
        dp[i] = inf;

    for (int i = 1; i <= n; i++)
        for (int j = maxn; j >= 1; j--)
            if (dp[j] + w[i] <= m)
                dp[j + v[i]] = std::min(dp[j + v[i]], dp[j] + w[i]);

    for (int i = maxn; i >= 1; i--)
    {
        if (dp[i] != inf)
        {
            std::cout << i;
            return 0;
        }
    }
}
