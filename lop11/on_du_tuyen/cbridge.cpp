#include <bits/stdc++.h>
#define task "cbridge"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 2e5 + 7;

int n, m;
std::vector<int> adj[maxn + 7];
int up[maxn + 7][20], h[maxn + 7];
int d[maxn + 7];
int ans = 0;

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (v == up[u][0])
        {
            continue;
        }

        h[v] = h[u] + 1;
        up[v][0] = u;

        for (int j = 1; j < 20; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
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

    if (h[u] < h[v])
    {
        std::swap(u, v);
    }

    int k = h[u] - h[v];
    for (int j = 0; (1 << j) <= k; j++)
    {
        if ((k >> j) & 1)
        {
            u = up[u][j];
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

void solve(int u)
{
    for (int v : adj[u])
    {
        if (v == up[u][0])
        {
            continue;
        }

        solve(v);

        if (d[v] > 0)
        {
            ans++;
        }
        d[u] += d[v];
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    std::cin >> m;
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;

        d[u]++;
        d[v]++;
        d[lca(u, v)] -= 2;
    }

    solve(1);

    std::cout << n - ans - 1;
    return 0;
}
