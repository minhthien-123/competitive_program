#include <bits/stdc++.h>
#define task ""
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5 + 5;
const int inf = 1e18;
int d[maxn];

int n, m;
std::vector<ii> adj[maxn];

void dijk(int s)
{
    std::fill(d, d + maxn, inf);

    d[s] = 0;
    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
    pq.push({0, s});

    while (pq.size())
    {
        ii t = pq.top();
        pq.pop();

        int w = t.fi;
        int u = t.se;

        if (w > d[u])
        {
            continue;
        }

        for (auto i : adj[u])
        {
            for (auto j : adj[i.fi])
            {
                int cost = w + i.se * j.se;
                if (d[j.fi] > cost)
                {
                    d[j.fi] = cost;
                    pq.push({d[j.fi], j.fi});
                }
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
        int u, v, c;
        std::cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }

    dijk(1);

    if (d[n] == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << d[n];
    }

    return 0;
}