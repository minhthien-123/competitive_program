#include <bits/stdc++.h>
#define task "lcs2"
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

int n, m, res;
std::string a, b, str;
int x[maxn + 7], y[maxn * maxn + 7];
int dp[maxn + 7][maxn + 7];
int f[maxn * maxn + 7][30];
bool g[maxn + 7][maxn + 7];

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

    std::cin >> a >> b;
    m = a.size();
    n = b.size();

    for (int i = 1; i <= m; i++)
    {
        x[i] = a[i - 1] - 'A';
    }
    for (int i = 1; i <= n; i++)
    {
        y[i] = b[i - 1] - 'A';
    }

    for (int i = 0; i < 26; i++)
    {
        f[n][i] = inf;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            f[i][j] = f[i + 1][j];
        }
        f[i][y[i + 1]] = i + 1;
    }

    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = inf;
        dp[i][0] = 0;
    }

    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] != inf)
            {
                if (f[dp[i - 1][j - 1]][x[i]] != inf)
                {
                    dp[i][j] = std::min(dp[i][j], f[dp[i - 1][j - 1]][x[i]]);
                }
            }
        }
    }

    res = m;
    while (dp[m][res] == inf)
    {
        res--;
    }

    str = "";

    //std::cout << res << "\n";

    for (int i = m; i >= 1; i--)
    {
        if (dp[i][res] != dp[i - 1][res])
        {
            char tmp = x[i] + 'A';
            str = tmp + str;
            res--;
        }
    }

    std::cout << str;

    return 0;
}