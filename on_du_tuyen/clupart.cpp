#include <bits/stdc++.h>
#define task "clupart"
#define int long long
#define ld long double
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
const ld  eps = 1e-12;

int n;
ld k;
int a[maxn + 7], dp[maxn + 7], par[maxn + 7];
bool check[maxn + 7][maxn + 7];

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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int len = j - i + 1;
            int tmp = a[j] - a[i] + 1;
            if ((ld)len + eps >= k * (ld)tmp)
            {
                check[i][j] = true;
            }
            else
            {
                check[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = inf;
        par[i] = -1;
    }

    dp[0] = 0;
    par[0] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (!check[j][i])
            {
                continue;
            }
            if (dp[i] > dp[j - 1] + 1)
            {
                dp[i] = dp[j - 1] + 1;
                par[i] = j - 1;
            }
        }
    }

    std::cout << dp[n] << "\n";

    if (dp[n] == 1)
    {
        std::cout << 0;
        return 0;
    }

    std::vector<int> path;

    int cur = n;
    while (cur > 0)
    {
        path.pb(cur);
        cur = par[cur];
    }

    std::reverse(path.begin(), path.end());

    for (int i = 0; i < path.size() - 1; i++)
    {
        std::cout << path[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
