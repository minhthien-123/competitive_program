#include <bits/stdc++.h>
#define task "transnet"
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

int n, m, k, s, t;
std::vector<ii> adj1[maxn + 7], adjn[maxn + 7];
int d1[maxn + 7], dn[maxn + 7];

void dijk(int s, int d[], std::vector<ii> adj[])
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

    std::cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj1[u].pb({v, w});
        adjn[v].pb({u, w});
    }

    dijk(s, d1, adj1);
    dijk(t, dn, adjn);

    int ans = d1[t];

    while (k--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (d1[u] != inf && dn[v] != inf)
        {
            ans = std::min(ans, d1[u] + w + dn[v]);
        }
        if (d1[v] != inf && dn[u] != inf)
        {
            ans = std::min(ans, d1[v] + w + dn[u]);
        }
    }
    std::cout << ans;

    return 0;
}