#include <bits/stdc++.h>
#define task "lck"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, q;
std::vector<int> adj[maxn + 7];
int up[maxn + 7][20], d[maxn + 7], st[4 * maxn + 7];

void dfs(int u, int p)
{
    up[u][0] = p;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

void init()
{
    for (int j = 1; j <= log2(n); j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v)
{
    if (!u || !v)
    {
        return u + v;
    }
    if (d[u] != d[v])
    {
        if (d[u] < d[v])
            std::swap(u, v);
        int k = d[u] - d[v];
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

    int k = std::__lg(d[u]);
    for (int j = k; j >= 0; --j)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);

    st[id] = lca(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return lca(get1, get2);
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

    dfs(1, 0);
    init();

    for (int i = 1; i <= n; i++)
    {
        update(1, 1, n, i, i);
    }

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        if (u > v)
        {
            std::swap(u, v);
        }
        std::cout << get(1, 1, n, u, v) << "\n";
    }

    return 0;
}