#include <bits/stdc++.h>
#define task "school"
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

int n, m;
std::vector<ii> adj[maxn + 7];
int d[maxn + 7], cnt[maxn + 7];

void dijk(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
        cnt[i] = 0;
    }
    d[s] = 0;
    cnt[s] = 1;
    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
    pq.push({0, s});

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
                cnt[v] = cnt[u];
                pq.push({d[v], v});
            }
            else if (d[u] + w == d[v])
            {
                cnt[v] = (cnt[v] + cnt[u]) % mod;
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
    while (m--)
    {
        int u, v, w, t;
        std::cin >> t >> u >> v >> w;
        if (t == 1)
        {
            adj[u].pb({v, w});
        }
        else
        {
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
    }

    dijk(1);

    if (d[n] == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << d[n] << " " << cnt[n];
    }

    return 0;
}