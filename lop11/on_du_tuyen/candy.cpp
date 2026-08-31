#include <bits/stdc++.h>
#define task "candy"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, a, b, c, s, ans = inf;
int p[maxn + 7];
bool dp[maxn + 7][maxn + 7];

void solve(int x, int y, int z, int pos)
{
    if (pos <= n)
    {
        solve(x + p[pos], y, z, pos + 1);
        solve(x, y + p[pos], z, pos + 1);
        solve(x, y, z + p[pos], pos + 1);
    }
    else
    {
        ans = std::min(std::max(x, std::max(y, z)) - std::min(x, std::min(y, z)), ans);
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
        s += p[i];
    }

    if (n <= 10)
    {
        solve(0, 0, 0, 1);
        std::cout << ans;
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= 0; j--)
        {
            for (int k = s; k >= 0; k--)
            {
                if (dp[j][k])
                {
                    if (j + p[i] <= s)
                    {
                        dp[j + p[i]][k] = 1;
                    }
                    if (k + p[i] <= s)
                    {
                        dp[j][k + p[i]] = 1;
                    }
                }
            }
        }
    }

    /*for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }*/

    for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (dp[i][j])
            {
                b = s - i - j;
                a = std::max(std::max(i, j), b);
                c = std::min(std::min(i, j), b);
                ans = std::min(ans, a - c);
            }
        }
    }

    std::cout << ans;

    return 0;
}
