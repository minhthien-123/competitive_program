#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;

int n, m;
std::vector<ii> adj[maxn + 7];
int d[maxn + 7][2];

void dijk(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i][0] = inf;
        d[i][1] = inf;
    }

    std::priority_queue<iii, std::vector<iii>, std::greater<>> pq;
    d[s][0] = 0;
    pq.push({{0, s}, 0});

    while (!pq.empty())
    {
        int cost = pq.top().fi.fi;
        int u = pq.top().fi.se;
        int check = pq.top().se;
        pq.pop();

        if (d[u][check] < cost)
            continue;

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;

            if (d[v][check] > d[u][check] + w)
            {
                d[v][check] = d[u][check] + w;
                pq.push({{d[v][check], v}, check});
            }

            if (check == 0 && d[v][1] > d[u][check])
            {
                d[v][1] = d[u][check];
                pq.push({{d[v][1], v}, 1});
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
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk(1);

    int ans = d[n][1];

    if (ans == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans;
    }
    return 0;
}
