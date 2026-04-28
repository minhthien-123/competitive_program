#include <bits/stdc++.h>
#define task "roads"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, k;
std::vector<iii> adj[maxn + 7];
int d[107][100007];

void dijk(int s)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            d[i][j] = inf;
        }
    }
    d[s][0] = 0;
    std::priority_queue<iii, std::vector<iii>, std::greater<>> pq;
    pq.push({d[s][0], {s, 0}});

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int du = tmp.fi;
        int u = tmp.se.fi;
        int t = tmp.se.se;
        if (du > d[u][t])
        {
            continue;
        }

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se.fi;
            int c = e.se.se;
            if (c + t > k)
            {
                continue;
            }
            if (d[v][c + t] > du + w)
            {
                d[v][c + t] = du + w;
                pq.push({d[v][c + t], {v, c + t}});
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

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> k >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w, t;
            std::cin >> u >> v >> w >> t;
            adj[u].pb({v, {w, t}});
            adj[v].pb({u, {w, t}});
        }

        dijk(1);

        int ans =inf;
        for (int i = 0; i <= k; i++)
        {
            ans = std::min(ans, d[n][i]);
        }
        if (ans == inf)
        {
            std::cout << -1;
        }
        else
        {
            std::cout << ans;
        }
        std::cout << "\n";
    }

    return 0;
}