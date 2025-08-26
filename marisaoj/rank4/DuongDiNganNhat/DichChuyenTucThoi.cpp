#include <bits/stdc++.h>
#define task ""
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

int n, m;
int d[maxn + 7][maxn + 7];

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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        d[u][v] = std::min(d[u][v], w);
        d[v][u] = std::min(d[v][u], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j] && d[i][k] != inf && d[k][j] != inf)
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << d[i][j] << " ";
        }
        std::cout << "\n";
    }*/

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int s = 0;
            for (int u = 1; u <= n; u++)
            {
                for (int v = u + 1; v <= n; v++)
                {
                    s += std::min({d[u][v], d[u][i] + d[j][v], d[u][j] + d[i][v]});
                }
            }
            ans = std::min(ans, s);
        }
    }

    std::cout << ans;

    return 0;
}
