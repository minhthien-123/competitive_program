#include <bits/stdc++.h>
#define task "D"
#define int long long
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 5e3;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x % mod * (y % mod)) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

std::vector<int> adj[maxn + 7];
int n, m;

struct LazySegTree
{
    int n;
    std::vector<long long> st, lazy;

    LazySegTree(int n)
    {
        this->n = n;
        st.assign(4 * n + 7, 1);
        lazy.assign(4 * n + 7, 0);
    }

    void push(int id)
    {
        if (lazy[id] != 0)
        {
            st[2 * id] = std::max(st[2 * id], lazy[id]);
            lazy[2 * id] = std::max(lazy[2 * id], lazy[id]);

            st[2 * id + 1] = std::max(st[2 * id + 1], lazy[id]);
            lazy[2 * id + 1] = std::max(lazy[2 * id + 1], lazy[id]);

            lazy[id] = 0;
        }
    }

    void update(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v)
        {
            st[id] = std::max(st[id], val);
            lazy[id] = std::max(lazy[id], val);
            return;
        }
        push(id);
        int mid = (l + r) / 2;
        update(2 * id, l, mid, u, v, val);
        update(2 * id + 1, mid + 1, r, u, v, val);
        st[id] = std::min(st[2 * id], st[2 * id + 1]);
    }

    long long get(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return INF;
        if (u <= l && r <= v)
            return st[id];
        push(id);
        int mid = (l + r) / 2;
        return std::min(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
    }
};

LazySegTree seg(0);

struct HLD
{
    int n, timer;
    std::vector<std::vector<int>> adj;
    std::vector<int> par, depth, heavy, head, pos, sz;

    HLD(int n)
    {
        this->n = n;
        timer = 0;
        adj.resize(n + 7);
        par.resize(n + 7);
        depth.resize(n + 7);
        heavy.assign(n + 7, -1);
        head.resize(n + 7);
        pos.resize(n + 7);
        sz.resize(n + 7);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int v, int p)
    {
        sz[v] = 1;
        par[v] = p;
        int max_sub = 0;
        for (int u : adj[v])
        {
            if (u != p)
            {
                depth[u] = depth[v] + 1;
                int sub_sz = dfs(u, v);
                sz[v] += sub_sz;
                if (sub_sz > max_sub)
                {
                    max_sub = sub_sz;
                    heavy[v] = u;
                }
            }
        }
        return sz[v];
    }

    void decompose(int v, int h, int p)
    {
        head[v] = h;
        pos[v] = ++timer;
        if (heavy[v] != -1)
        {
            decompose(heavy[v], h, v);
        }
        for (int u : adj[v])
        {
            if (u != p && u != heavy[v])
            {
                decompose(u, u, v);
            }
        }
    }

    void build(int root = 1)
    {
        depth[root] = 0;
        dfs(root, root);
        decompose(root, root, root);
    }

    long long query_path(int u, int v)
    {
        long long res = INF;
        while (head[u] != head[v])
        {
            if (depth[head[u]] < depth[head[v]])
                std::swap(u, v);
            res = std::min(res, seg.get(1, 1, n, pos[head[u]], pos[u]));
            u = par[head[u]];
        }
        if (depth[u] > depth[v])
            std::swap(u, v);
        res = std::min(res, seg.get(1, 1, n, pos[u] + 1, pos[v]));
        return res;
    }

    void update_path(int u, int v, long long val)
    {
        while (head[u] != head[v])
        {
            if (depth[head[u]] < depth[head[v]])
                std::swap(u, v);
            seg.update(1, 1, n, pos[head[u]], pos[u], val);
            u = par[head[u]];
        }
        if (depth[u] > depth[v])
            std::swap(u, v);
        seg.update(1, 1, n, pos[u] + 1, pos[v], val);
    }
};

std::vector<ii> edges;
std::vector<iii> queries;

void solve()
{
    std::cin >> n;
    HLD hld(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        hld.add_edge(u, v);
        edges.pb({u, v});
    }

    hld.build(1);
    seg = LazySegTree(n);

    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        queries.pb({{u, v}, w});
    }

    for (auto q : queries)
    {
        hld.update_path(q.fi.fi, q.fi.se, q.se);
    }

    for (auto q : queries)
    {
        int w = hld.query_path(q.fi.fi, q.fi.se);
        if (w != q.se)
        {
            std::cout << -1 << "\n";
            return;
        }
    }

    for (auto [u, v] : edges)
    {
        int child;
        if (hld.depth[u] > hld.depth[v])
        {
            child = u;
        }
        else
        {
            child = v;
        }

        int ans = seg.get(1, 1, n, hld.pos[child], hld.pos[child]);
        std::cout << ans << " ";
    }
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int tt = 1;
    // std::cin >> tt;
    while (tt--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣿⣿⣷⣦⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⡿⡿⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⡿⠯⣩⣾⣾⣿⣿⣿⡚⣛⣝⢕⢕⢝⢝⢽⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⡿⣨⣿⣿⣿⣿⠿⣛⡭⢓⣿⣿⣷⣕⢷⣥⠥⢝⣿⣿⣿⡿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⡿⢿⠟⣭⣿⣿⣿⣫⣾⡫⣯⢿⢷⢶⢿⣶⢮⣟⣩⣴⡻⢷⡆⣿⣿⢕⢙⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⡛⡡⠊⣴⣿⣿⣟⢽⢟⣿⣑⣙⣾⠺⣸⡾⡏⣚⡛⣿⣯⡡⢜⣧⢝⣿⣞⡪⡹⣿⣿⣿⡏⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡯⡫⢪⣒⠿⣽⣿⣟⣼⣿⣿⣕⣪⣿⠯⣫⣿⡯⡭⣮⣻⣿⣯⢝⣿⣿⣬⢼⣿⣪⡫⡻⣿⣿⣿⡍⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣴⡿⡾⠺⡴⣾⣿⣿⢗⣟⣿⣿⠅⣶⣿⣯⢎⣾⡿⡪⣾⡧⣾⣿⠵⢕⣿⣿⣇⢵⣿⣏⡮⠪⣻⣿⡾⡮⡹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣧⣿⣴⣿⣿⢓⣟⣿⢯⢏⣵⡿⣹⣿⣺⣿⡏⡇⣿⡿⣿⣿⢹⢘⣿⣿⣯⠕⣿⣿⣿⡬⣏⢻⣿⠯⣭⢺⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣟⣼⣿⣿⣿⣿⣿⢵⣿⣿⡯⡼⡲⣿⠗⣻⣿⣾⡟⢽⢺⣿⡧⣿⡿⡧⡣⣿⣿⡿⡟⣿⣿⣿⣷⢻⡼⣿⣿⣿⠲⣻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣀⠀⣀⣠⡤⣾⣞⣿⣿⣿⣿⣿⣟⡭⣿⣾⣿⠀⠨⣸⡏⠀⢹⣿⣿⠘⡗⢼⣿⣿⢿⢸⡺⠺⣿⣿⣟⡢⣿⣿⣿⣿⣿⣿⢜⣿⣿⡯⣪⣧⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠚⠋⣡⢟⣾⣿⣿⣿⣟⢿⠭⢵⣻⣿⣿⠀⢨⣺⡇⠀⠸⣿⣿⠀⠹⢝⣿⣿⣿⡇⢯⡪⡮⣿⡯⡪⢿⣿⣿⣿⣿⣿⣷⢛⣿⣿⣾⣾⠀⠀⠀⢀⡴⠏⠻⠛⡧⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡼⣻⣿⣿⣿⣿⡟⣗⣳⢼⣏⡻⡩⠿⢤⠼⢾⣿⠀⠀⠹⢿⣇⠀⠳⣽⣿⣿⣷⡈⢮⡪⣻⣟⣒⣻⣿⣿⣿⣿⣿⣿⣕⣿⣿⣿⣿⡆⠀⠀⠘⢷⡆⣠⣙⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢯⣽⣿⣟⣥⢹⣵⣿⢮⣿⣷⣴⣿⣶⣾⣦⣤⣄⠀⠀⠀⠈⠉⠁⠀⠈⠙⢻⣛⡻⡎⢻⣽⣯⣆⣯⣿⣿⣿⣿⣿⣿⣧⡺⢟⣱⠞⣦⣀⡀⠀⠈⠙⠉⠉⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠻⡎⣶⣿⣿⣫⣾⣿⠟⠋⠁⠀⠉⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣥⣩⠛⠲⣼⣗⢧⢖⡺⣿⣯⣺⣻⣿⣿⡄⢯⡈⠀⠀⣴⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⢫⣿⣿⣿⣫⣿⣿⡗⠀⢀⠂⡄⠀⠀⠀⠀⠀⠐⠳⠒⠀⠀⠀⠀⠉⠉⠙⠿⢯⣒⣼⣯⢝⣿⣮⡻⣿⣧⣪⡻⣿⡏⡸⠧⠼⣦⠉⢳⠋⢹⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⣿⣿⣿⣿⣿⣿⡧⠢⠃⡐⠀⠀⠀⡖⠒⠤⠤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⡀⡹⢿⣿⠗⣿⣿⣿⣾⣯⡿⡪⡿⣿⣞⡟⣵⠛⠁⠀⠀⠛⣶⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣽⣧⠆⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠈⠉⠙⢳⡄⠀⡰⡜⡠⢁⠽⢿⣽⣿⣿⣿⣿⣿⣮⢮⣻⣗⣿⣬⣛⣿⣀⡽⠛⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣷⣄⠀⠀⠀⠀⠹⡀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⢠⢠⢁⠎⣠⣿⣿⣿⣿⣿⣿⢿⣿⣟⣽⣿⣿⣿⣿⠈⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣻⣿⣿⣿⢻⣿⣿⣿⣕⣿⣿⣿⣿⣷⣦⡀⠀⠀⠁⠀⠀⠀⠀⠀⣠⡤⠖⠁⠀⠀⠀⠁⠘⢎⣸⣺⣿⣿⣿⢿⣿⣽⣿⣿⣿⣿⣿⣿⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢰⣿⡿⣿⣿⢣⣿⢿⣿⢗⣽⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣠⣤⣴⣶⣿⣿⣿⡾⣿⣿⣷⢽⣷⣿⣿⣿⣿⣿⣿⣿⣾⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣾⣰⣿⣯⢞⣷⣿⣟⣅⣿⣿⣿⠿⠿⠿⠿⠿⠛⠛⠛⠿⣿⣯⡿⡫⡡⠽⣿⠽⠟⣿⣿⣿⣿⣿⣿⣺⣿⣿⣗⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣻⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣿⣇⣿⣽⢳⣿⣿⠱⣼⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣯⠾⠚⠉⠀⠀⠀⣟⢛⡿⠛⠉⣻⣿⣿⣿⣻⡧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣧⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⢿⡿⣯⣽⣺⣿⣟⢴⢟⣥⣛⡇⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⠋⠉⠀⠀⠀⠀⠀⠀⣻⠞⠁⠀⠀⣯⣿⣿⣿⣟⣕⣿⡿⣿⣿⣿⣿⣿⣿⣫⡯⣯⣿⣷⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⡺⣺⡿⠿⣾⣿⢣⡭⢿⠀⠹⠖⢶⡀⠀⠀⠀⠀⠀⡼⢭⣉⡀⠀⠀⠀⠀⠀⢀⡜⠁⠀⠀⠀⠸⣿⣿⣿⣿⢷⣗⢿⣿⡿⢋⣹⣿⣿⣿⣿⡪⡿⣾⣺⣿⣄⠀⠀⠀
⠀⠀⠀⢀⡼⣯⣾⣯⣯⣽⣿⣿⠜⢦⡤⠀⠀⢲⡟⠀⠀⠀⠀⠀⢐⡇⠀⠀⠉⠛⠒⠶⠶⣶⠋⠀⠀⠀⠀⠀⣮⣾⣿⣿⣿⣟⣿⣝⢽⠞⣑⢑⣿⣿⣿⣿⡯⣯⣻⣯⣯⣽⣦⠀⠀
⠀⠀⢠⣻⣮⣿⣟⣜⢿⢽⣿⣟⠀⡸⣤⡼⠷⡶⠇⠀⠀⠀⠀⠀⢸⢤⡀⠀⠀⠀⠀⢀⡴⠁⠀⠀⠀⠀⠀⢰⣻⣿⣿⢿⣿⡯⣿⣷⢿⣇⠆⠄⣿⣿⣿⣿⣿⡿⣾⣿⣷⡿⢿⣆⠀
⠀⣰⣿⣷⣿⣿⣷⣝⣵⢽⡿⠫⠰⠸⢸⢸⠸⣿⢇⣀⣠⣄⠀⠀⢸⠀⠀⠀⠀⠉⢉⡟⠀⠀⠀⠀⠀⠀⠀⣇⣿⣿⡏⣾⣿⡿⣿⣿⣺⡻⣴⠙⢾⣿⣿⣿⣿⣷⣿⢿⣿⣿⣺⡻⡇
⢸⡧⢽⣿⣿⣿⣿⠝⣷⠻⠟⢻⡆⠊⡮⠊⣇⠟⣿⡈⠃⠼⣆⠀⠸⠀⠀⠀⠀⢀⠎⠀⠀⠀⠀⠀⠀⠀⢰⣕⢿⣿⢿⢯⣿⣿⣿⣿⣮⡯⡷⣎⣻⣿⣿⣿⣿⣿⣿⣽⣿⣿⣫⡯⣧
⠈⢿⢿⣿⣿⣿⣿⠇⡟⢀⠀⢈⣹⡆⣸⡯⢻⣌⠷⢶⣀⡶⠛⠀⠀⠀⠀⠀⢀⡎⠀⠀⠀⠀⠀⢀⣠⣲⡿⣗⣿⣿⣽⣗⣿⣿⣿⣿⣿⣿⡫⣿⣿⣿⣿⣿⣿⣿⣗⣿⣿⣿⡷⣪⣿
⠀⠀⠛⣿⣿⣿⣿⢵⣽⣟⠦⠞⠁⡊⡪⣿⢨⡿⣯⣳⣭⣤⡀⠀⢠⠀⠀⠀⡘⠀⠀⠀⢀⣤⣾⡿⢋⣥⢾⢷⣷⢿⣇⢿⣏⣿⣿⣿⣿⣯⡿⣯⣺⣿⣿⣿⣵⣿⣿⣿⣿⣿⡯⡫⡎
⠀⠀⠀⠈⢿⣿⣿⡟⣿⣧⣿⣬⠠⢀⠡⢣⣼⡧⠊⠻⣝⣿⣿⢆⢸⠀⠀⢰⠁⢀⣠⣾⡿⠟⣡⠔⠋⠔⡀⡼⣟⣾⣽⣄⣿⣝⣿⣿⣿⣷⣿⣿⢻⣎⣿⣽⣿⣿⡿⣿⣿⣿⡯⣻⠇
*/