#include <bits/stdc++.h>
#define task ""
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e4;
const int inf  = 1e5;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;
const int bl   = 225;

struct mo
{
    int u, x, pos;
} query[maxn + 7];

int n, q;
int a[maxn + 7];
int cnt[maxn + 7];
std::vector<int> col[maxn + 7];
std::vector<int> adj[maxn + 7], heavy;
int up[maxn + 7][20], h[maxn + 7], d[230][maxn + 7];
int f[maxn + 7];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (up[u][0] == v)
        {
            continue;
        }

        h[v] = h[u] + 1;
        up[v][0] = u;

        for (int j = 1; j <= 19; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
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
        for (int j = 0; (1 << j) <= k; j++)
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

int dist(int u, int v)
{
    int p = lca(u, v);
    return h[u] + h[v] - 2 * h[p];
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

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        col[a[i]].pb(i);
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i].size() > bl)
        {
            heavy.pb(i);
        }
    }

    for (int i = 0; i < heavy.size(); i++)
    {
        f[heavy[i]] = i;
        std::queue<int> qu;
        for (int u = 1; u <= n; u++)
        {
            d[i][u] = inf;
        }
        for (auto u : col[heavy[i]])
        {
            qu.push(u);
            d[i][u] = 0;
        }

        while (qu.size())
        {
            int u = qu.front();
            qu.pop();
            for (int v : adj[u])
            {
                if (d[i][v] > d[i][u] + 1)
                {
                    d[i][v] = d[i][u] + 1;
                    qu.push(v);
                }
            }
        }
    }

    dfs(1);

    while (q--)
    {
        int u, x;
        std::cin >> u >> x;
        if (col[x].empty())
        {
            std::cout << "-1\n";
        }
        else
        {
            if (col[x].size() <= bl)
            {
                int ans = inf;
                for (int i : col[x])
                {
                    ans = std::min(ans, dist(u, i));
                }
                std::cout << ans << "\n";
            }
            else
            {
                std::cout << d[f[x]][u] << "\n";
            }
        }
    }

    return 0;
}
