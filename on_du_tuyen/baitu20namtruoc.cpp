#include <bits/stdc++.h>
#define task "baitu20namtruoc"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e4;
const int inf = (int)1e18;

int n;
int a[maxn + 7][4];
int dp[maxn + 7][1 << 4];
int sum[maxn + 7][1 << 4];
int mx = -inf;

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
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j][i];
            mx = std::max(mx, a[j][i]);
        }
    }

    if (mx < 0)
    {
        std::cout << mx;
        return 0;
    }

    std::vector<int> v;
    for (int mask = 0; mask < (1 << 4); mask++)
    {
        bool check = true;
        for (int j = 0; j + 1 < 4; j++)
        {
            if ((mask & (1 << j)) && (mask & (1 << (j + 1))))
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            v.pb(mask);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int mask : v)
        {
            int s = 0;
            for (int j = 0; j < 4; j++)
            {
                if (mask & (1 << j))
                {
                    s += a[i][j];
                }
            }
            sum[i][mask] = s;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < (1 << 4); j++)
        {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int mask : v)
        {
            for (int nmask : v)
            {
                if ((mask & nmask) == 0)
                {
                    dp[i][mask] = std::max(dp[i][mask], dp[i - 1][nmask] + sum[i - 1][mask]);
                }
            }
        }
    }

    int ans = -inf;
    for (int mask : v)
    {
        ans = std::max(ans, dp[n][mask]);
    }
    std::cout << ans << "\n";
    return 0;
}
