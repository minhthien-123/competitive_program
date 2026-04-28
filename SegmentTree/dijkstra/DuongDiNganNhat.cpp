#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e9;
const int mod  = 1e9 + 7;

int n, m;
std::vector<ii> adj[maxn];
int d[maxn], cnt[maxn], mx[maxn], mn[maxn];

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }

    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
    pq.push({0, s});
    d[s] = 0;
    cnt[s] = 1;

    while (pq.size())
    {
        ii t = pq.top();
        pq.pop();

        int u = t.se;
        if (d[u] == inf) continue;

        for (ii e : adj[u])
        {
            int v = e.fi;
            int w = e.se;

            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
                cnt[v] = cnt[u];
                mx[v] = mx[u] + 1;
                mn[v] = mn[u] + 1;
            }
            else if (d[u] + w == d[v])
            {
                cnt[v] += cnt[u];
                cnt[v] %= mod;
                mx[v] = std::max(mx[v], mx[u] + 1);
                mn[v] = std::min(mn[v], mn[u] + 1);
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    dijkstra(1);

    if (d[n] == inf)
    {
        std::cout << -1;
        return 0;
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        std::cout << cnt[i] << " ";
    }
    */


    std::cout << d[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n];

    return 0;
}
