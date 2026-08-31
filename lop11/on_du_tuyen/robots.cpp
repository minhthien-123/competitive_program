#include <bits/stdc++.h>
#define task "robots"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, s, t;
std::vector<ii> adj[maxn + 7], g[maxn + 7];
int num[maxn + 7], low[maxn + 7], timer;
bool flag[maxn + 7];
ii edge[maxn + 7];
int d1[maxn + 7], d2[maxn + 7];

void tarjan(int u, int p)
{
    low[u] = num[u] = ++timer;

    for (auto tmp : g[u])
    {
        int v = tmp.fi;
        int id = tmp.se;

        if (id == p)
        {
            continue;
        }

        if (!num[v])
        {
            tarjan(v, id);
            low[u] = std::min(low[u], low[v]);

            if (low[v] > num[u])
            {
                flag[id] = true;
            }
        }
        else
        {
            low[u] = std::min(low[u], num[v]);
        }
    }
}

void dijkstra(int S, int d[])
{
    std::priority_queue<ii, std::vector<ii>, std::greater<>> pq;

    d[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int du = tmp.fi;
        int u = tmp.se;
        if (du > d[u])
        {
            continue;
        }

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;

            if (d[v] > du + w)
            {
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
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

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edge[i] = {u, v};
        g[u].pb({v, i});
        g[v].pb({u, i});
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    std::cin >> s >> t;

    std::fill(d1 + 1, d1 + n + 1, inf);
    std::fill(d2 + 1, d2 + n + 1, inf);

    dijkstra(s, d1);
    dijkstra(t, d2);

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            tarjan(u, -1);
        }
    }

    int ans = inf;
    for (int i = 1; i <= m; i++)
    {
        if (!flag[i])
        {
            continue;
        }
        int u = edge[i].fi;
        int v = edge[i].se;
        int t1 = std::max(d1[u], d2[v]);
        int t2 = std::max(d1[v], d2[u]);
        ans = std::min({ans, t1, t2});
    }

    std::cout << ans;
    return 0;
}
