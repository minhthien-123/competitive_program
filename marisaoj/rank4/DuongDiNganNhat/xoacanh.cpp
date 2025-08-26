#include <bits/stdc++.h>
#define task "xoacanh"
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

int n, m, k;
std::vector<ii> adj[maxn + 7];
int dp[maxn + 7][10];

void dijk()
{
    std::priority_queue<iii, std::vector<iii>, std::greater<>> pq;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = inf;
        }
    }

    dp[1][0] = 0;
    pq.push({{0, 1}, 0});

    while (!pq.empty())
    {
        int cnt = pq.top().se;
        int cost = pq.top().fi.fi;
        int u = pq.top().fi.se;
        pq.pop();
        if (dp[u][cnt] < cost)
            continue;

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;

            if (dp[v][cnt] > dp[u][cnt] + w)
            {
                dp[v][cnt] = dp[u][cnt] + w;
                pq.push({{dp[v][cnt], v}, cnt});
            }
            if (cnt < k && dp[v][cnt + 1] > dp[u][cnt])
            {
                dp[v][cnt + 1] = dp[u][cnt];
                pq.push({{dp[v][cnt + 1], v}, cnt + 1});
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
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk();

    int res = inf;
    for (int i = 0; i <= k; i++)
    {
        res = std::min(res, dp[n][i]);
    }

    if (res == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << res;
    }

    return 0;
}
