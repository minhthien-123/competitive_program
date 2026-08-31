#include <bits/stdc++.h>
#define task "posivice"
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

int n, m;
std::vector<int> adj[maxn + 7];
int up[maxn + 7][20], h[maxn + 7];
int a[maxn + 7], tin[maxn + 7], timer;
int st[4 * maxn + 7], node[4 * maxn + 7];

void dfs(int u)
{
    tin[u] = ++timer;
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

void update(int id, int l, int r, int pos, int val, int u)
{
    if (pos < l || r < pos)
    {
        return;
    }

    if (l == r)
    {
        if (val >= st[id])
        {
            st[id] = val;
            node[id] = u;
        }
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val, u);
    update(id * 2 + 1, mid + 1, r, pos, val, u);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int get_left(int id, int l, int r, int x, int y, int u)
{
    if (r < x || l > y)
    {
        return -1;
    }
    if (st[id] < a[u])
    {
        return -1;
    }
    if (l == r && st[id] >= a[u])
    {
        return node[id];
    }
    int mid = (l + r) / 2;
    if (y <= mid)
    {
        return get_left(id * 2, l, mid, x, y, u);
    }
    else
    {
        int res = get_left(id * 2 + 1, mid + 1, r, mid + 1, y, u);
        if (res != -1)
        {
            return res;
        }
        return get_left(id * 2, l, mid, x, mid, u);
    }
}
int get_right(int id, int l, int r, int x, int y, int u)
{
    if (x > y)
    {
        return -1;
    }
    if (r < x || l > y)
    {
        return -1;
    }
    if (st[id] < a[u])
    {
        return -1;
    }
    if (l == r && st[id] >= a[u])
    {
        return node[id];
    }
    int mid = (l + r) / 2;
    if (x > mid)
    {
        return get_right(id * 2 + 1, mid + 1, r, x, y, u);
    }
    else
    {
        int res = get_right(id * 2, l, mid, x, mid, u);
        if (res != -1)
        {
            return res;
        }
        return get_right(id * 2 + 1, mid + 1, r, mid + 1, y, u);
    }
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

    std::cin >> n >> a[1];
    n++;
    for (int u = 2, v; u <= n; u++)
    {
        std::cin >> a[u] >> v;
        v++;
        adj[v].pb(u);
    }

    dfs(1);

    update(1, 1, n, 1, a[1], 1);
    for (int u = 2; u <= n; u++)
    {
        int l = get_left(1, 1, n, 1, tin[u] - 1, u);
        int r = get_right(1, 1, n, tin[u] + 1, n, u);

        int p = -1, q = -1;
        if (l != -1)
        {
            p = lca(l, u);
        }
        if (r != -1)
        {
            q = lca(r, u);
        }

        if (p == -1 || (q != -1 && h[p] < h[q]))
        {
            std::swap(p, q);
        }

        if (l == -1 && r == -1)
        {
            std::cout << h[u] << "\n";
        }
        else
        {
            std::cout << (h[u] - h[p] - 1) << "\n";
        }
        update(1, 1, n, tin[u], a[u], u);
    }

    return 0;
}
