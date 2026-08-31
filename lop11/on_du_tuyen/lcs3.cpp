#include <bits/stdc++.h>
#define task "lcs3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int tt = 1e6;

int n, m;
int a[maxn + 7], b[maxn * maxn + 7];
int dp[maxn + 7][maxn + 7];
std::vector<int> d[2 * tt + 7];

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

    std::cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
        d[b[i] + tt].pb(i);
    }

    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = inf;
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] != inf)
            {
                auto pos = std::upper_bound(d[a[i] + tt].begin(), d[a[i] + tt].end(), dp[i - 1][j - 1]);
                if (pos != d[a[i] + tt].end())
                {
                    dp[i][j] = std::min(dp[i][j], *pos);
                }
            }
        }
    }

    int res = m;
    while (dp[m][res] == inf)
    {
        res--;
    }

    std::vector<int> ans;
    for (int i = m; i >= 1; i--)
    {
        if (dp[i][res] != dp[i - 1][res])
        {
            ans.pb(a[i]);
            res--;
        }
    }

    std::reverse(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for (auto i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}