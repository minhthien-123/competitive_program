#include <bits/stdc++.h>
#define task "frog"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m, k;
int a[maxn + 7][maxn + 7], par[maxn + 7][maxn + 7], dp[maxn + 7][maxn + 7];
int path[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            dp[i][j] = inf;
            par[i][j] = -1;
        }
    }

    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = a[1][j];
        par[1][j] = 0;
    }

    for (int i = 2; i <= m; i++)
    {
        std::deque<int> dq;

        int tmp = 0;

        for (int j = 1; j <= n; j++)
        {
            int l = std::max(1LL, j - k);
            int r = std::min(n, j + k);

            while (tmp < r)
            {
                tmp++;
                while (dq.size() && dp[i - 1][dq.back()] <= dp[i - 1][tmp])
                {
                    dq.pop_back();
                }
                dq.pb(tmp);
            }
            while (dq.size() && dq.front() < l)
            {
                dq.pop_front();
            }
            dp[i][j] = dp[i - 1][dq.front()] + a[i][j];
            par[i][j] = dq.front();
        }
    }

    int ans = -inf;
    int t = -1;
    for (int j = 1; j <= n; j++)
    {
        if (dp[m][j] > ans)
        {
            ans = dp[m][j];
            t = j;
        }
    }

    path[m] = t;
    for (int i = m - 1; i >= 1; i--)
    {
        path[i] = par[i + 1][path[i + 1]];
    }

    std::cout << ans << "\n";
    for (int i = 1; i <= m; i++)
    {
        std::cout << path[i] << "\n";
    }

    return 0;
}
