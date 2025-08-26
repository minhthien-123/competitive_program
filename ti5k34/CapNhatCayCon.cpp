#include <bits/stdc++.h>
#define task "salary"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, q;
std::vector<int> adj[maxn];
int tin[maxn], tout[maxn], timer = 0;
int st[4 * maxn], lz[4 * maxn];

void dfs(int id, int v)
{
    tin[id] = ++timer;
    for (int u : adj[id])
    {
        if (u != v)
        {
            dfs(u, id);
        }
    }
    tout[id] = timer;
}

void fix(int id, int l, int r)
{
    if (lz[id] != 0)
    {
        st[id] += lz[id] * (r - l + 1);
        if (l != r)
        {
            lz[id * 2] += lz[id];
            lz[id * 2 + 1] += lz[id];
        }
        lz[id] = 0;
    }
}

void update(int id, int l, int r, int x, int y, int v)
{
    fix(id, l, r);
    if (l > y || r < x)
    {
        return;
    }
    if (l >= x && r <= y)
    {
        lz[id] += v;
        fix(id, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, x, y, v);
    update(id * 2 + 1, mid + 1, r, x, y, v);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int l, int r, int idx)
{
    fix(id, l, r);
    if (l == r)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
    {
        return query(id * 2, l, mid, idx);
    }
    else
    {
        return query(id * 2 + 1, mid + 1, r, idx);
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

    std::cin >> n >> q;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);

    while (q--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int u, v;
            std::cin >> u >> v;
            update(1, 1, n, tin[u], tout[u], v);
        }
        else if (type == 2)
        {
            int u;
            std::cin >> u;
            std::cout << query(1, 1, n, tin[u]) << '\n';
        }
    }

    return 0;
}
