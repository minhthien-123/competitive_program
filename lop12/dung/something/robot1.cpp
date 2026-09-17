#include <bits/stdc++.h>
#define task "robot1"
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

const int maxn = 2e5;
const ll inf = 1e18;
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
    return (x * y) % mod;
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

struct Edge
{
    int v, c;
    ll p;
};

int n, m;
std::vector<Edge> g[maxn + 7];
std::map<int, ll> sum[maxn + 7];
std::map<int, int> id[maxn + 7];

struct Dijkstra
{
    int n;
    std::vector<std::vector<std::pair<int, long long>>> adj;
    std::vector<long long> dist;

    Dijkstra(int n)
    {
        this->n = n;
        adj.resize(n + 7);
        dist.assign(n + 7, inf);
    }

    void add_edge(int u, int v, long long w)
    {
        adj[u].push_back({v, w});
    }

    void run(int s)
    {
        dist.assign(n + 7, inf);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : adj[u])
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};

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

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        ll p;
        std::cin >> u >> v >> c >> p;
        g[u].pb({v, c, p});
        g[v].pb({u, c, p});
        sum[u][c] += p;
        sum[v][c] += p;
    }

    int idx = n;

    for (int i = 1; i <= n; i++)
    {
        for (auto [v, c, p] : g[i])
        {
            if (id[i].find(c) == id[i].end())
            {
                id[i][c] = ++idx;
            }
        }
    }

    Dijkstra dijk(idx);

    for (int u = 1; u <= n; u++)
    {
        for (auto it : id[u])
        {
            dijk.add_edge(it.se, u, 0);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        for (auto [v, c, p] : g[u])
        {
            dijk.add_edge(u, v, p);
            dijk.add_edge(u, id[v][c], sum[u][c] - p);
            dijk.add_edge(id[u][c], v, p);
        }
    }

    dijk.run(1);

    if (dijk.dist[n] == inf)
    {
        std::cout << -1 << "\n";
    }
    else
    {
        std::cout << dijk.dist[n] << "\n";
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
