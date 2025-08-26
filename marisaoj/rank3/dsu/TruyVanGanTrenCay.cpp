#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn];
int n, q;
int a[maxn], par[maxn], h[maxn];

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v != p)
        {
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v, u);
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

    std::cin >> n >> q;
    for (int i = 1, u, v; i < n; i++)
    {
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    while (q--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        std::vector<int> res;
        while (h[y] > h[x])
        {
            if (a[y] == 0)
            {
                a[y] = z;
            }
            res.pb(y);
            y = par[y];
        }
        if (a[x] == 0)
        {
            a[x] = z;
        }
        for (int y : res)
        {
            par[y] = par[x];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}
