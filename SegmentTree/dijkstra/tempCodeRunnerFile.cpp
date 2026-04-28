#include <bits/stdc++.h>
#define task "dijkstra"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, s, t;
int a[maxn];
std::vector<ii> adj[maxn];
int d[maxn];

void dijk(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    std::priority_queue<ii, std::vector<ii>, std::greater<>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int du = tmp.fi;
        int u = tmp.se;
        if (du != d[u])
        {
            continue;
        }

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;
            if (a[v] != 0 && d[u] + w >= a[v])
            {
                continue;
            }
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
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

    std::cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk(s);

    if (d[t] == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << d[t];
    }

    return 0;
}