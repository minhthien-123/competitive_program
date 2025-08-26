#include <bits/stdc++.h>
#define task "lca"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100000;

int n, q;
std::vector<int> adj[maxn + 1];
int h[maxn + 1], up[maxn + 1][20];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (v == up[u][0])
            continue;
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
    for (int j = 0; j < 20; j++)
    {
        if (k & (1 << j))
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

int find(int u, int k)
{
    for (int j = 0; j < 20; j++)
    {
        if (k & (1 << j))
        {
            u = up[u][j];
        }
    }
    return u;
}

int solve(int u, int v, int w)
{
    int p = lca(u, v);
    int du = h[u] - h[p];
    int dv = h[v] - h[p];
    int k = du + dv;

    if (w <= du)
    {
        return find(u, w);
    }
    if (w >= k)
    {
        return v;
    }
    return find(v, dv - (w - du));
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    up[1][0] = 0;
    h[1] = 0;
    dfs(1);

    while (q--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        std::cout << solve(u, v, w) << "\n";
    }
    return 0;
}
