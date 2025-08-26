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
std::vector<int> adj[maxn + 7];
int h[maxn + 7], up[maxn + 7][20], sz[maxn + 7];

void dfs(int u, int p)
{
    sz[u] = 1;
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
        sz[u] += sz[v];
    }
}

int find(int u, int k)
{
    for (int j = 0; (1 << j) <= k; j++)
    {
        if (k >> j & 1)
        {
            u = up[u][j];
        }
    }
    return u;
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
        u = find(u, k);
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
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;

        int k = lca(u, v);
        int d = h[u] + h[v] - 2 * h[k];
        if (d % 2 != 0)
        {
            std::cout << "0\n";
        }
        else
        {
            if (h[u] > h[v])
            {
                std::swap(u, v);
            }
            int rv = find(v, d / 2 - 1);
            int mid = up[rv][0];
            if (h[u] == h[v])
            {
                int ru = find(u, d / 2 - 1);
                std::cout << sz[1] - sz[ru] - sz[rv] << "\n";
            }
            else
            {
                std::cout << sz[mid] - sz[rv] << "\n";
            }
        }
    }

    return 0;
}
