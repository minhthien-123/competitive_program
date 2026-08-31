#include <bits/stdc++.h>
#define task ""
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
const int S = 320;

struct mo
{
    int l, r, p, idx;
} query[maxn + 7];

bool cmp(mo a, mo b)
{
    if (a.l / S != b.l / S)
    {
        return a.l / S < b.l / S;
    }
    else
    {
        if ((a.l / S) & 1)
        {
            return a.r > b.r;
        }
        else
        {
            return a.r < b.r;
        }
    }
}

int n, q, m, a[maxn + 7], dco[maxn + 7], cnt[maxn + 7];
bool vis[maxn + 7];
int tin[maxn + 7], tout[maxn + 7], tour[2 * maxn + 7], timer;
int up[maxn + 7][20], h[maxn + 7];
ii st[4 * maxn + 7];
std::vector<int> adj[maxn + 7];
std::map<int, int> mp, co;
int res[maxn + 7];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].fi = l;
        st[id].se = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].fi = -1;
    st[id].se = 0;
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }

    if (l == r)
    {
        st[id].se += val;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);

    if (st[id * 2].se > st[id * 2 + 1].se)
    {
        st[id] = {st[id * 2].fi, st[id * 2].se};
    }
    else
    {
        st[id] = {st[id * 2 + 1].fi, st[id * 2 + 1].se};
    }
}

void upd(int u)
{
    if (vis[u])
    {
        update(1, 1, m, a[u], -1);
    }
    else
    {
        update(1, 1, m, a[u], 1);
    }

    vis[u] = !vis[u];
}

void dfs(int u)
{
    tin[u] = ++timer;
    tour[timer] = u;
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
    tout[u] = ++timer;
    tour[timer] = u;
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
        for (int j = 0; (1LL << j) <= k; j++)
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

int dist(int u, int v)
{
    int p = lca(u, v);
    return h[u] + h[v] - 2 * h[p];
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
        mp[a[i]] = true;
    }

    for (auto i : mp)
    {
        co[i.fi] = ++m;
        dco[m] = i.fi;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = co[a[i]];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    build(1, 1, m);

    for (int i = 1; i <= q; i++)
    {
        int u, v;
        std::cin >> u >> v;
        if (tin[u] > tin[v])
        {
            std::swap(u, v);
        }
        int p = lca(u, v);
        if (u == p)
        {
            query[i] = {tin[u], tin[v], p, i};
        }
        else
        {
            query[i] = {tout[u], tin[v], p, i};
        }
    }

    std::sort(query + 1, query + q + 1, cmp);

    int l = 1, r = 0;

    for (auto q : query)
    {
        while (l > q.l)
        {
            l--;
            upd(tour[l]);
        }
        while (r < q.r)
        {
            r++;
            upd(tour[r]);
        }
        while (l < q.l)
        {
            upd(tour[l]);
            l++;
        }
        while (r > q.r)
        {
            upd(tour[r]);
            r--;
        }
        int u = tour[q.l];
        int v = tour[q.r];
        if (q.p != u && q.p != v)
        {
            upd(q.p);
        }
        int need = ((dist(u, v) + 1) / 2) + 1;
        if (st[1].se >= need)
        {
            res[q.idx] = dco[st[1].fi];
        }
        else
        {
            res[q.idx] = -1;
        }
        if (q.p != u && q.p != v)
        {
            upd(q.p);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << res[i] << "\n";
    }

    return 0;
}
