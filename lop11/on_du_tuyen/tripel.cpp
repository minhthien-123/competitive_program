#include <bits/stdc++.h>
#define task "tripel"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
std::vector<int> adj[maxn + 7];
int tin[maxn + 7], tour[maxn + 7], tout[maxn + 7], timer;
int up[maxn + 7][20], h[maxn + 7];

void dfs(int u)
{
    tin[u] = ++timer;
    for (int v : adj[u])
    {
        if (up[u][0] == v)
        {
            continue;
        }

        up[v][0] = u;
        h[v] = h[u] + 1;

        for (int j = 1; j <= 19; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
    tout[u] = ++timer;
}

int lca(int u, int v)
{
    if (!u || !v)
    {
        return u + v;
    }

    if (h[u] != h[v])
    {
        if (h[u] < h[v])
        {
            std::swap(u, v);
        }
        int k = h[u] - h[v];

        for (int j = 0; j <= 19; j++)
        {
            if (k >> j & 1)
            {
                u = up[u][j];
            }
        }
    }

    if (u == v)
    {
        return u;
    }

    for (int j = 19; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
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

    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        std::vector<ii> vec;

        for (int j = i; j <= n; j += i)
        {
            vec.pb({tin[j], j});
        }

        std::sort(vec.begin(), vec.end());

        int v = 1, ans = 0;
        for (auto e : vec)
        {
            int u = e.se;
            int p = lca(u, v);
            ans += h[u] + h[v] - 2 * h[p];
            v = u;
        }

        ans += h[v] + h[1] - 2 * h[lca(v, 1)];

        std::cout << ans << "\n";
    }

    return 0;
}
