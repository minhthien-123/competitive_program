#include <bits/stdc++.h>
#define task "lca"
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

int n, q;
std::vector<ii> adj[maxn + 7];
int h[maxn + 7], up[maxn + 7][20], mx[maxn + 7][20];

void dfs(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.fi;
        int w = e.se;
        if (v == p)
        {
            continue;
        }
        h[v] = h[u] + 1;
        up[v][0] = u;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v])
    {
        std::swap(u, v);
    }

    int ans = 0;
    int k = h[u] - h[v];
    for (int j = 0; j < 20; j++)
    {
        if (k & (1 << j))
        {
            ans = std::max(ans, mx[u][j]);
            u = up[u][j];
        }
    }

    if (u == v)
    {
        return ans;
    }

    for (int j = 19; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            ans = std::max({ans, mx[u][j], mx[v][j]});
            u = up[u][j];
            v = up[v][j];
        }
    }

    return std::max({ans, mx[u][0], mx[v][0]});
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

    std::cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    h[1] = 0;
    up[1][0] = 1;
    mx[1][0] = 0;
    dfs(1, -1);

    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
            mx[i][j] = std::max(mx[i][j - 1], mx[up[i][j - 1]][j - 1]);
        }
    }

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca(u, v) << "\n";
    }

    return 0;
}
