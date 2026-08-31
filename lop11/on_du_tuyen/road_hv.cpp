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

std::vector<ii> b[maxn + 7], w[maxn + 7], rb[maxn + 7], rw[maxn + 7];
int db[maxn + 7], dw[maxn + 7], drb[maxn + 7], drw[maxn + 7];
int n, m, k, x;

void dijk(int s, std::vector<ii> adj[], int d[])
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
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
            int wgt = e.se;
            if (d[u] + wgt < d[v])
            {
                d[v] = d[u] + wgt;
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

    std::cin >> n >> m >> k >> x;

    while (m--)
    {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        w[u].pb({v, x});
        rw[v].pb({u, x});
        b[u].pb({v, y});
        rb[v].pb({u, y});
    }

    dijk(1, b, db);
    dijk(n, rb, drb);
    dijk(k, rw, drw);

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        if (db[i] == inf || drb[i] == inf || drw[i] == inf)
        {
            continue;
        }
        if (db[i] + drw[i] <= x)
        {
            ans = std::min(ans, db[i] + drb[i]);
        }
    }

    if (ans == inf)
    {
        ans = -1;
    }
    std::cout << ans << '\n';

    return 0;
}
