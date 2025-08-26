#include <bits/stdc++.h>
#define task "paint"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;

int m, n;
int a[maxn][maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans ++;
            ans += std::max((int)0, a[i][j] - a[i - 1][j]);
            ans += std::max((int)0, a[i][j] - a[i][j - 1]);
            ans += std::max((int)0, a[i][j] - a[i + 1][j]);
            ans += std::max((int)0, a[i][j] - a[i][j + 1]);
        }
    }

    std::cout << ans;

    return 0;
}
