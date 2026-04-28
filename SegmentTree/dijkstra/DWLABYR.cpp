#include <bits/stdc++.h>
#define task "DWLABYR"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 300;
const int inf = (int)1e18;
const int mod = (int)1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, k;
int adj[maxn + 7][maxn + 7], d[maxn + 7][maxn + 7];
bool flag[maxn + 7];
std::vector<int> a;

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

    std::cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = inf;
            adj[i][j] = inf;
        }
        flag[i] = false;
    }

    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u][v] = std::min(adj[u][v], w);
    }

    while (k--)
    {
        char type;
        std::cin >> type;
        if (type == 'X')
        {
            int u;
            std::cin >> u;
            if (flag[u])
            {
                continue;
            }
            flag[u] = true;
            a.pb(u);
            d[u][u] = 0;

            for (int v : a)
            {
                if (v != u)
                {
                    d[u][v] = std::min(d[u][v], adj[u][v]);
                    d[v][u] = std::min(d[v][u], adj[v][u]);
                }
            }

            for (int x : a)
            {
                if (x != u)
                {
                    for (int v : a)
                    {
                        d[u][v] = std::min(d[u][v], adj[u][x] + d[x][v]);
                    }

                    for (int v : a)
                    {
                        d[v][u] = std::min(d[v][u], d[v][x] + adj[x][u]);
                    }
                }
            }

            for (int i : a)
            {
                for (int j : a)
                {
                    d[i][j] = std::min(d[i][j], d[i][u] + d[u][j]);
                }
            }
        }
        else
        {
            int s, t;
            std::cin >> s >> t;
            if (d[s][t] == inf)
            {
                std::cout << -1 << "\n";
            }
            else
            {
                std::cout << d[s][t] << "\n";
            }
        }
    }

    return 0;
}
