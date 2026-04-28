#include <bits/stdc++.h>
#define task "hnriver"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::vector<iii> adj[maxn + 7];
int d[maxn + 7], par[maxn + 7];

void dijk(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
        par[i] = -1;
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
            int t = e.se.fi;
            int c = e.se.se;
            int timer = std::max(d[u], t);
            timer += c;
            if (timer < d[v])
            {
                d[v] = timer;
                par[v] = u;
                pq.push({d[v], v});
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
    while (m--)
    {
        int u, v, t, c;
        std::cin >> u >> v >> t >> c;
        adj[u].pb({v, {t, c}});
        adj[v].pb({u, {t, c}});
    }

    dijk(1);
    std::cout << d[n] << "\n";

    std::vector<int> path;

    while (n != -1)
    {
        path.pb(n);
        n = par[n];
    }

    std::reverse(path.begin(), path.end());

    for (int i : path)
    {
        std::cout << i << " ";
    }

    return 0;
}
