#include <bits/stdc++.h>
#define task "game"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e2;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int Log = 20;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, q;
int a[maxn + 7][maxn + 7];
int par[maxn * maxn + 7], sz[maxn * maxn + 7];
int d[maxn * maxn + 7];
int parent[Log + 7][maxn * maxn + 7], f[Log + 7][maxn * maxn + 7];

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

bool join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            std::swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

int idx(int i, int j)
{
    return (i - 1) * n + j;
}

struct edge
{
    int u, v, w;
};

bool cmp(edge x, edge y)
{
    return x.w > y.w;
}

std::vector<ii> adj[maxn * maxn + 7];
std::vector<edge> edges;

void dfs(int u, int p)
{
    for (auto tmp : adj[u])
    {
        int v = tmp.fi;
        int w = tmp.se;
        if (v == p)
            continue;
        parent[0][v] = u;
        f[0][v] = w;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int get(int u, int v)
{
    if (u == v)
    {
        int i = (u - 1) / n + 1;
        int j = (u - 1) % n + 1;
        return a[i][j];
    }
    if (find(u) != find(v))
        return -1;

    int ans = inf;
    if (d[u] < d[v])
        std::swap(u, v);
    int diff = d[u] - d[v];

    for (int k = 0; k < Log; k++)
        if (diff & (1LL << k))
        {
            ans = std::min(ans, f[k][u]);
            u = parent[k][u];
        }

    if (u == v)
        return ans;

    for (int k = Log - 1; k >= 0; k--)
    {
        if (parent[k][u] != parent[k][v])
        {
            ans = std::min({ans, f[k][u], f[k][v]});
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    ans = std::min({ans, f[0][u], f[0][v]});
    return ans;
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
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j];

    for (int v = 1; v <= n * n; v++)
        init(v);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int u = idx(i, j);
            if (i + 1 <= n)
            {
                int v = idx(i + 1, j);
                edges.pb({u, v, std::min(a[i][j], a[i + 1][j])});
            }
            if (j + 1 <= n)
            {
                int v = idx(i, j + 1);
                edges.pb({u, v, std::min(a[i][j], a[i][j + 1])});
            }
        }
    }

    std::sort(edges.begin(), edges.end(), cmp);

    for (auto &e : edges)
        if (join(e.u, e.v))
        {
            adj[e.u].pb({e.v, e.w});
            adj[e.v].pb({e.u, e.w});
        }

    d[1] = 0;
    parent[0][1] = 1;
    f[0][1] = inf;
    dfs(1, 0);

    for (int k = 1; k < Log; k++)
        for (int v = 1; v <= n * n; v++)
        {
            int u = parent[k - 1][v];
            parent[k][v] = parent[k - 1][u];
            f[k][v] = std::min(f[k - 1][v], f[k - 1][u]);
        }

    while (q--)
    {
        int sx, sy, tx, ty;
        std::cin >> sx >> sy >> tx >> ty;
        int u = idx(sx, sy);
        int v = idx(tx, ty);
        std::cout << get(u, v) << '\n';
    }

    return 0;
}
