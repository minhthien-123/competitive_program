#include <bits/stdc++.h>
#define task ""
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
std::vector<int> adj[maxn + 7];
int tin[maxn + 7], tout[maxn + 7], tour[maxn + 7], timer;

void dfs(int u, int p)
{
    tour[++timer] = u;
    tin[u] = timer;

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }

    tout[u] = timer;
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
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        if (tin[u] <= tin[v] && tout[v] <= tout[u])
        {
            std::cout << "MA\n";
        }
        else if (tin[v] <= tin[u] && tout[u] <= tout[v])
        {
            std::cout << "RI\n";
        }
        else
        {
            std::cout << "SA\n";
        }
    }

    return 0;
}
