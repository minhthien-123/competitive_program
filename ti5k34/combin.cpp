#include <bits/stdc++.h>
#define task "combin"
#define int long long

const int maxn = 1e3;
const int inf = 1e18;

int n, k, m, cnt = 1;
int dp[maxn + 7][maxn + 7];

void init()
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}

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

    std::cin >> n >> k >> m;

    init();

    while (k > 0)
    {
        if (m < dp[n - 1][k - 1])
        {
            std::cout << cnt << " ";
            k--;
        }
        else
        {
            m -= dp[n - 1][k - 1];
        }
        cnt++;
        n--;
    }

    return 0;
}
