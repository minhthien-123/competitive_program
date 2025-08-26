#include <bits/stdc++.h>
#define task "stones"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 300;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int dp[maxn + 7][maxn + 7], d[maxn + 7][maxn + 7];
int sx, sy, n, m;
std::string a[maxn + 7], s;

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
    std::cin >> sx >> sy;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = inf;
        }
    }

    dp[sx - 1][sy - 1] = 0;

    for (char c : s)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                d[i][j] = dp[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    d[i][j] = std::min(d[i][j], d[i - 1][j] + 1);
                }
                if (j > 0)
                {
                    d[i][j] = std::min(d[i][j], d[i][j - 1] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i + 1 < n)
                {
                    d[i][j] = std::min(d[i][j], d[i + 1][j] + 1);
                }
                if (j + 1 < m)
                {
                    d[i][j] = std::min(d[i][j], d[i][j + 1] + 1);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == c)
                {
                    dp[i][j] = d[i][j];
                }
                else
                {
                    dp[i][j] = inf;
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = std::min(ans, dp[i][j]);
        }
    }

    std::cout << ans << "\n";
    return 0;
}