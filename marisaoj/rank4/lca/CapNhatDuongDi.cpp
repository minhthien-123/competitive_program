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

int n, q;
std::vector<int> adj[maxn + 7];
int h[maxn + 7], up[maxn + 7][20];
int ans[maxn + 7], f[maxn + 7];

void dfs(int u, int p)
{
    for (int v : adj[u])
    {

        if (v == p)
        {
            continue;
        }

        h[v] = h[u] + 1;
        up[v][0] = u;
        for (int j = 1; j < 20; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v, u);
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
        for (int j = 0; j < 20; j++)
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

void dfs2(int u, int p)
{
    ans[u] = f[u];
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs2(v, u);
        ans[u] += ans[v];
    }
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
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);

    while (q--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        int p = lca(u, v);
        f[u] += w;
        f[v] += w;
        f[p] -= w;
        if (up[p][0] != 0)
        {
            f[up[p][0]] -= w;
        }
    }

    dfs2(1, -1);

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << " ";
    }

    return 0;
}
