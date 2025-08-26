#include <bits/stdc++.h>
#define task "board"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3;
const int inf = 1e18;

int m, n;
int a[maxn + 7][maxn + 7], dp[maxn + 7][maxn + 7];

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
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = -inf;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        dp[i][1] = a[i][1];
    }

    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            int best = -inf;
            if (i > 1)
            {
                best = std::max(best, dp[i - 1][j - 1]);
            }
            best = std::max(best, dp[i][j - 1]);
            if (i < m)
            {
                best = std::max(best, dp[i + 1][j - 1]);
            }
            dp[i][j] = best + a[i][j];
        }
    }

    int ans = -inf, posi = 1;
    for (int i = 1; i <= m; i++)
    {
        if (dp[i][n] > ans)
        {
            ans = dp[i][n];
            posi = i;
        }
    }
    std::cout << ans << "\n";

    std::vector<ii> v;
    int posj = n;
    while (posj >= 1)
    {
        v.pb(ii(posi, posj));
        if (posj == 1)
        {
            break;
        }
        int cur = dp[posi][posj] - a[posi][posj];
        int x = posi;
        if (posi > 1 && dp[posi - 1][posj - 1] == cur)
        {
            x = posi - 1;
        }
        else if (dp[posi][posj - 1] == cur)
        {
            x = posi;
        }
        else if (posi < m && dp[posi + 1][posj - 1] == cur)
        {
            x = posi + 1;
        }
        posi = x;
        posj--;
    }

    std::reverse(v.begin(), v.end());

    for (auto i : v)
    {
        std::cout << i.fi << " " << i.se << "\n";
    }

    return 0;
}
