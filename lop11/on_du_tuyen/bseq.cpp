#include <bits/stdc++.h>
#define task "bseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf = 1e18;
int n, m;
int a[maxn + 7], b[maxn + 7];
int dp0[maxn + 7][maxn + 7], dp1[maxn + 7][maxn + 7];
int ans;

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

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> b[i];
    }

    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));

    ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp0[i][j] = std::max(dp0[i - 1][j], dp0[i][j - 1]);
            dp1[i][j] = std::max(dp1[i - 1][j], dp1[i][j - 1]);

            if (a[i] <= b[j])
            {
                dp0[i][j] = std::max(dp0[i][j], 1LL);
                if (dp1[i - 1][j - 1] > 0)
                {
                    dp0[i][j] = std::max(dp0[i][j], dp1[i - 1][j - 1] + 1);
                }
            }
            if (a[i] >= b[j])
            {
                dp1[i][j] = std::max(dp1[i][j], 1LL);
                if (dp0[i - 1][j - 1] > 0)
                {
                    dp1[i][j] = std::max(dp1[i][j], dp0[i - 1][j - 1] + 1);
                }
            }
        }
        ans = std::max(ans, std::max(dp0[i][m], dp1[i][m]));
    }

    std::cout << ans;

    return 0;
}