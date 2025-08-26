#include <bits/stdc++.h>
#define ll long long
#define pb push_back

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn];
int par[maxn], d[maxn], n, k, m;
bool vis[maxn];
int ans = 0;

void bfs(int u)
{
    std::fill_n(d, n + 9, -1);
    std::fill_n(vis, n + 9, false);

    std::queue<int> q;
    q.push(u);
    d[u] = 0;
    vis[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto e : adj[v])
        {
            if (!vis[e])
            {
                vis[e] = true;
                d[e] = d[v] + 1;
                q.push(e);
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // std::freopen(task".inp", "r", stdin);
    // std::freopen(task".out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int m;
        std::cin >> m;
        for (int j = 1, k; j <= m; j++)
        {
            std::cin >> k;
            adj[i].pb(k);
        }
    }

    bfs(k);
    for (int i = 1; i <= n; i++)
        if (d[i] != -1)
            ans++;

    std::cout << ans << "\n";

    for (int i = 1; i <= n; i++)
        if (d[i] != -1)
            std::cout << i << " ";

    return 0;
}
