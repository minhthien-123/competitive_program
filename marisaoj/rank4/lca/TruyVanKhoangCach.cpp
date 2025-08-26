#include <bits/stdc++.h>
#define task "lca"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, q;
std::vector<ii> adj[maxn + 7];
int h[maxn + 7], up[maxn + 7][18], d[maxn + 7];

void dfs(int u)
{
    for (ii e : adj[u])
    {
        int v = e.fi;
        int w = e.se;
        if (v == up[u][0])
        {
            continue;
        }

        h[v] = h[u] + 1;
        d[v] = d[u] + w;

        up[v][0] = u;
        for (int j = 1; j < 10; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] < h[v])
        {
            std::swap(u, v);
        }

        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
        {
            if (k >> j & 1)
            {
                u = up[u][j];
            }
        }
    }
    if (u == v)
    {
        return u;
    }

    int k = std::__lg(h[u]);
    for (int j = k; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int solve(int u, int v)
{
    int p = lca(u, v);
    return d[u] + d[v] - 2 * d[p];
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

    std::cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dfs(1);

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << solve(u, v) << "\n";
    }

    return 0;
}