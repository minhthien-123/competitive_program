#include <bits/stdc++.h>
#define task "A"
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

int n, m, k;
std::vector<ii> adj[maxn + 7], res, v;
int d[maxn + 7], vis[maxn + 7], par[maxn + 7];
ii g[maxn + 7];
std::map<ii, ii> mp;
ii ans[maxn + 7];
bool f[maxn + 7];


struct cmp
{
    bool operator()(ii a, ii b)
    {
        return a.se > b.se;
    }
};

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }

    std::vector<bool> p(n, 0);
    std::priority_queue<ii, std::vector<ii>, cmp> pq;
    d[s] = 0;
    pq.push({s, d[s]});

    while (!pq.empty())
    {
        ii x = pq.top();
        pq.pop();

        int u = x.fi;
        if (p[u] == true)
            continue;

        p[u] = true;
        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        bool w;
        std::cin >> u >> v >> w;
        f[i] = w;
        adj[u].pb(ii(v, w));
        adj[v].pb(ii(u, w));
        g[i] = ii(u, v);
    }

    dijkstra(1);

    //std::cout << d[n] << "\n";

    if (d[n] < k)
    {
        std::cout << "No";
        return 0;
    }

    std::cout << "Yes\n";
    for (int i = 1; i <= m; i++)
    {
        if (f[i])
        {
            std::cout << std::min({d[g[i].fi] + 1, d[g[i].se] + 1, k}) << "\n";
        }
    }

    return 0;
}
