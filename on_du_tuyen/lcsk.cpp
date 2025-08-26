#include <bits/stdc++.h>
#define task "lcsk"
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
int a[maxn + 7], b[maxn + 7];
ii par[maxn + 7][maxn + 7];
int dp[maxn + 7][maxn + 7];

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
        std::cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        std::cin >> b[j];
    }

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                int mx = 0;
                for (int x = std::max(1ll, i - k); x < i; x++)
                {
                    for (int y = std::max(1ll, j - k); y < j; y++)
                    {
                        if (dp[x][y] > mx)
                        {
                            mx = dp[x][y];
                            par[i][j] = ii(x, y);
                        }
                    }
                }
                dp[i][j] = mx + 1;

                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    par[0][0] = ii(i, j);
                }
            }
        }
    }

    std::vector<int> resa, resb;

    ii pos = par[0][0];
    while (pos.fi > 0 && pos.se > 0 && dp[pos.fi][pos.se] > 0)
    {
        resa.pb(pos.fi);
        resb.pb(pos.se);
        pos = par[pos.fi][pos.se];
    }

    std::reverse(resa.begin(), resa.end());
    std::reverse(resb.begin(), resb.end());

    std::cout << ans << "\n";
    for (auto i : resa)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    for (auto i : resb)
    {
        std::cout << i << " ";
    }

    return 0;
}
