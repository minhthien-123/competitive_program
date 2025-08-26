#include <bits/stdc++.h>
#define task "salary"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, q, timer = 0;
std::vector<int> adj[maxn];
int tin[maxn], tout[maxn], a[maxn], tour[maxn];
int st[4 * maxn], lz[4 * maxn];

void dfs(int id, int v)
{
    tin[id] = ++timer;
    tour[timer] = id;
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

void build(int id, int l, int r)
{
    if (tour[l] == tour[r])
    {
        st[id] = a[tour[l]];
        return;
    }

    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
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

    int mid = l + r >> 1;
    update(id * 2, l, mid, x, y, v);
    update(id * 2 + 1, mid + 1, r, x, y, v);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int l, int r, int pos)
{
    fix(id, l, r);
    if (l == r)
    {
        return st[id];
    }
    int mid = l + r >> 1;
    if (pos <= mid)
    {
        return query(id * 2, l, mid, pos);
    }
    else
    {
        return query(id * 2 + 1, mid + 1, r, pos);
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

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (i != 1)
        {
            int w;
            std::cin >> w;
            adj[w].pb(i);
            adj[i].pb(w);
        }
        //update(1, 1, n, i, i, a[i]);
    }

    dfs(1, -1);
    build(1, 1, n);

    while (q--)
    {
        char type;
        std::cin >> type;
        if (type == 'p')
        {
            int u, v;
            std::cin >> u >> v;
            update(1, 1, n, tin[u] + 1, tout[u], v);
        }
        else if (type == 'u')
        {
            int u;
            std::cin >> u;
            std::cout << query(1, 1, n, tin[u]) << '\n';
        }
    }

    return 0;
}