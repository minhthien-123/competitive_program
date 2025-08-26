#include <bits/stdc++.h>
#define task "votree"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 7e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, q;
std::vector<int> adj[maxn + 7];
int up[maxn + 7][20], h[maxn + 7];
int ans[maxn + 7][20];
int st[4 * maxn + 7];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (up[u][0] == v)
        {
            continue;
        }

        h[v] = h[u] + 1;
        up[v][0] = u;

        for (int j = 1; j <= 19; j++)
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

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
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
    int mid = (l + r) >> 1;
    int left = get(id * 2, l, mid, u, v);
    int right = get(id * 2 + 1, mid + 1, r, u, v);
    return lca(left, right);
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

    dfs(1);

    build(1, 1, n);

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << get(1, 1, n, u, v) << "\n";
    }

    return 0;
}
