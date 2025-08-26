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
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::vector<int> adj[maxn + 7];
int up[maxn + 7][20], h[maxn + 7];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (up[u][0] == v)
        {
            continue;
        }

        up[v][0] = u;
        h[v] = h[u] + 1;

        for (int j = 1; j < 20; j++)
        {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        dfs(v);
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
        for (int j = 0; (1 << j) <= k; j++)
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

    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
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

    std::cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca(u, v) << " ";
    }

    return 0;
}
