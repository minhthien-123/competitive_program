#include <bits/stdc++.h>
#define task ""
#define int long long
#define pb push_back
#define ins insert

const int maxn = 100000;

int n;
int a[maxn + 5];
std::vector<int> adj[maxn + 5];
std::set<int> color[maxn + 5];
int ans[maxn + 5];

void dfs(int u, int p)
{
    int heavy = -1;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        if (v != p)
        {
            dfs(v, u);
            if (heavy == -1 || color[v].size() > color[heavy].size())
            {
                heavy = v;
            }
        }
    }

    if (heavy == -1)
    {
        color[u].clear();
    }
    else
    {
        color[u] = color[heavy];
    }

    for (int v : adj[u])
    {
        if (v == p || v == heavy)
        {
            continue;
        }

        for (int val : color[v])
        {
            color[u].ins(val);
        }
        color[v].clear();
    }

    color[u].insert(a[u]);
    ans[u] = color[u].size();
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i)
    {
        std::cout << ans[i] << " ";
    }

    return 0;
}