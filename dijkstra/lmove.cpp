#include <bits/stdc++.h>
#define task "dijkstra"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 101;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int e1, w1, e2, w2, s, x, y;
std::vector<ii> adj[maxn + 7];
int d[maxn + 7];

void dijk(int s)
{
    for (int i = 1; i <= maxn; i++)
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

    std::cin >> e1 >> w1;
    std::cin >> e2 >> w2;
    std::cin >> s;
    std::cin >> x >> y;

    for (int i = 0; i < 100; i++)
    {
        adj[i].pb({i + 1, s});
        adj[i + 1].pb({i, s});
    }

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (i == j)
                continue;
            int cost = w1 + e1 * abs(i - j);
            adj[i].emplace_back(j, cost);
        }
    }

    std::vector<int> a;
    for (int t = 0; t <= 100; t += 10)
    {
        a.push_back(t);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            int u = a[i];
            int v = a[j];
            int cost = w2 + e2 * (abs(u - v) / 10);
            adj[u].emplace_back(v, cost);
        }
    }

    dijk(x);

    std::cout << d[y];

    return 0;
}