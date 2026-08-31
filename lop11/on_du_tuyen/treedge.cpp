#include <bits/stdc++.h>
#define task "treedge"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, q;
std::vector<ii> adj[maxn + 7];
int up[maxn + 7][20], h[maxn + 7], d[maxn + 7], d2[maxn + 7];

void dfs(int u)
{
    for (auto tmp : adj[u])
    {
        int v = tmp.fi;
        int w = tmp.se;

        if (up[u][0] == v)
        {
            continue;
        }

        up[v][0] = u;
        h[v] = h[u] + 1;
        d[v] = d[u] + w;

        for (int j = 1; j <= 19; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
}

void dfs2(int u, int p)
{
    d2[u] = 0;
    for (auto tmp : adj[u])
    {
        int v = tmp.fi;
        int w = tmp.se;
        if (v == p)
        {
            continue;
        }

        dfs2(v, u);
        d2[u] = std::max(d2[u], d2[v] + w);
    }
}

int lca(int u, int v)
{
    if (!u || !v)
    {
        return u + v;
    }

    if (h[u] != h[v])
    {
        if (h[u] < h[v])
        {
            std::swap(u, v);
        }
        int k = h[u] - h[v];

        for (int j = 0; j <= 19; j++)
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

    for (int j = 19; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
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
    dfs2(1, -1);

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << d2[i] << " ";
    }
    std::cout << "\n";*/

    while (q--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        int p = lca(u, v);
        //std::cout << d[u] + d[v] - 2 * d[p] << " ";
        std::cout << std::max(d[u] + d[v] - 2 * d[p], d2[u] + d2[v] + w) << "\n";
    }

    return 0;
}
